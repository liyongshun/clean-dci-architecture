//
// Created by Darwin Yuan on 2020/7/1.
//

#ifndef TRANS_DSL_2_FORKHELPER_H
#define TRANS_DSL_2_FORKHELPER_H

#include <trans-dsl/tsl_config.h>
#include <trans-dsl/sched/domain/ThreadId.h>
#include <trans-dsl/sched/action/SchedFork.h>
#include <trans-dsl/sched/concepts/ConceptHelper.h>
#include <trans-dsl/sched/domain/ThreadBitMap.h>
#include <trans-dsl/sched/concepts/SchedActionConcept.h>

TSL_NS_BEGIN

namespace details {
   template <ThreadId TID, typename T_ACTION>
   class Fork final {
      static_assert(TID < ThreadBitMap::max, "specified Thread ID is out of scope");
      static_assert(TID != 0, "0 is main thread, which has already been created");

   public:
      template<TransListenerObservedAids const& AIDs>
      class ActionRealType : public SchedFork {
         using ActionType = ActionRealTypeTraits_t<AIDs, T_ACTION>;
         struct Inner {
            struct ThreadActionCreator {
               static constexpr ThreadId threadId = TID;
               static constexpr uint8_t  numOfThreads = 1;
               auto createThreadAction(ThreadId tid) -> SchedAction * {
                  if (tid == TID) {
                      present = true;
                      return new(cache) ActionType;
                  }

                  return nullptr;
               }

               ~ThreadActionCreator() {
                   if(present) {
                       ActionType* elem = reinterpret_cast<ActionType*>(cache);
                       elem->~ActionType();
                       present = false;
                   }
               }

            private:
               alignas(alignof(ActionType)) char cache[sizeof(ActionType)];
               bool present{false};
            };
         };

         OVERRIDE(getThreadId() const -> ThreadId) { return TID; }
      public:
         using ThreadActionCreator = ThreadCreator_t<Inner, ActionType>;
      };
   };
}

#define __fork(tid, ...) TSL_NS::details::Fork<tid, TSL_NS::details::AutoAction::SequentialTrait_t<__VA_ARGS__>>

TSL_NS_END

#endif //TRANS_DSL_2_FORKHELPER_H
