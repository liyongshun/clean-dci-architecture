CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

PROJECT("clean-dci-arch")

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
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wnon-virtual-dtor \
      -Wcast-align -Wunused -Woverloaded-virtual -Wconversion \
      -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 \
      -Wno-invalid-offsetof ")
endif()

FILE(GLOB_RECURSE all_files 
include/*.h
include/*.hpp
include/*.hxx
include/*.tcc
src/*.cpp
src/*.cc
src/*.cxx
src/*.c
src/*.C
test/*.h
test/*.hpp
test/*.hxx
test/*.tcc
test/*.cpp
test/*.cc
test/*.cxx
test/*.c
test/*.C)

sort_files(all_files)

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/3th/lib")

add_executable(clean-dci-arch ${all_files})

target_link_libraries(clean-dci-arch gtest trans-dsl-2 pthread stdc++)

