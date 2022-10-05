CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

project(
  clean-dci-arch
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

MACRO(sort_files source_files)
    SET(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
    FOREACH(sgbd_file ${${source_files}})
        STRING(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
        STRING(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
        STRING(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
        IF(MSVC)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
        ENDIF(MSVC)
        IF(sgbd_nogroup)
            SET(sgbd_group_name "\\")
        ENDIF(sgbd_nogroup)
        SOURCE_GROUP(${sgbd_group_name} FILES ${sgbd_file})
    ENDFOREACH(sgbd_file)
ENDMACRO(sort_files)

# include(cmake/CPM.cmake)

INCLUDE_DIRECTORIES( 
"${CMAKE_CURRENT_SOURCE_DIR}/include"
"${CMAKE_CURRENT_SOURCE_DIR}/test"
"${CMAKE_CURRENT_SOURCE_DIR}/3th/include"
)

IF(MSVC)
  ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS )
  ADD_DEFINITIONS(-DMSVC_VMG_ENABLED)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /vmg")
ENDIF(MSVC)

if(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

file(GLOB_RECURSE headers CONFIGURE_DEPENDS 
"${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS 
"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")


file(GLOB_RECURSE tests CONFIGURE_DEPENDS 
"${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

sort_files(headers)
sort_files(sources)

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/3th/lib")

add_library(${PROJECT_NAME} STATIC ${headers} ${sources})
# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

add_executable("${PROJECT_NAME}_test" ${tests})

if(MSVC80)
    target_link_libraries(${PROJECT_NAME} trans-dsl-2 gtest-vc80)
elseif(MSVC90)
    target_link_libraries(${PROJECT_NAME} trans-dsl-2 gtest-vc90)
elseif(MSVC10)
    target_link_libraries(${PROJECT_NAME} trans-dsl-2 gtest-vc10)
else(UNIX)
    target_link_libraries("${PROJECT_NAME}_test" ${PROJECT_NAME} gtest trans-dsl-2 pthread stdc++)
endif(MSVC80)
