//
// Created by Darwin Yuan on 2020/7/11.
//

#ifndef TRANS_DSL_2_TYPELISTZIP_H
#define TRANS_DSL_2_TYPELISTZIP_H

#include <cub/cub_ns.h>
#include <type_traits>
#include <cub/type-list/Tuple.h>
#include <cub/type-list/TypeListValueWrapper.h>

CUB_NS_BEGIN

namespace details {
   template <typename IN_1, typename IN_2, typename = void, typename ... OUT>
   struct Zip {
      using type = TypeList<OUT...>;
   };

   template <typename IN_1, typename IN_2, typename ... OUT>
   class Zip<IN_1, IN_2, std::void_t<typename IN_1::Head, typename IN_2::Head>, OUT...> {
      using Elem1 = typename IN_1::Head;
      using Elem2 = typename IN_2::Head;

   public:
      using type = typename Zip
         < typename IN_1::Tail
         , typename IN_2::Tail
         , void, OUT..., __TL_make_pair(Elem1, Elem2)
         >::type;
   };
}

namespace type_list {
   template<typename IN_1, typename IN_2>
   using ZipWith_t = typename details::Zip<IN_1, ListWrapper<IN_2>, void>::type;
}

template<typename IN_2, template<typename ...> typename RESULT, typename ... Ts>
using ZipWith_t = typename type_list::ZipWith_t<TypeList<Ts...>, IN_2>::template output<RESULT>;

template<typename IN_2, template<typename ...> typename RESULT, typename ... Ts>
using ZipWith_tt = typename ZipWith_t<IN_2, RESULT, Ts...>::type;

CUB_NS_END

#endif //TRANS_DSL_2_TYPELISTZIP_H
