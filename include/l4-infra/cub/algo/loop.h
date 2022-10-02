#ifndef HC8777C2D_A6D2_4569_B639_4B3B68B935C6
#define HC8777C2D_A6D2_4569_B639_4B3B68B935C6

#include <l4-infra/cub/base/BaseTypes.h>
#include <l4-infra/cub/cub.h>

CUB_NS_BEGIN

#define FOR_EACH(i, begin, end)   for(U32 i = begin; i< end; ++i)

#define FOR_EACH_0(i, max) FOR_EACH(i, 0, max)

#define ALWAYS_LOOP()  while(true)

CUB_NS_END

#endif 
