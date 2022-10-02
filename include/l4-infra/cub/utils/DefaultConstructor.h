#ifndef HF6201AF3_C3A9_47FC_A3A6_1C91D7F33FEC
#define HF6201AF3_C3A9_47FC_A3A6_1C91D7F33FEC

#include <l4-infra/cub/base/BaseTypes.h>
#include <l4-infra/cub/mem/Placement.h>

CUB_NS_BEGIN

/////////////////////////////////////////////////////////////////
template<bool hasDefaultConstructor>
struct DefaultConstructor
{
    template <typename T>
    static void construct(Placement<T>elem);

    template <typename T, size_t N>
    static void construct(Placement<T>(&elems)[N]);
};

/////////////////////////////////////////////////////////////////
template<> struct DefaultConstructor<true>
{
    template <typename T>
    static void construct(Placement<T>elem)
    {
        new (elem.alloc()) T();
    }

    template <typename T, size_t N>
    static void construct(Placement<T>(&elems)[N])
    {
        for(size_t i = 0; i < N; i++)
        {
            new (elems[i].alloc()) T();
        }
    }
};

CUB_NS_END

#endif
