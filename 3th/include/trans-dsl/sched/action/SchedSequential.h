//
// Created by Darwin Yuan on 2020/6/8.
//

#ifndef TRANS_DSL_2_SCHEDSEQUENTIAL_H
#define TRANS_DSL_2_SCHEDSEQUENTIAL_H

#include <trans-dsl/sched/domain/SchedAction.h>
#include <trans-dsl/utils/ActionStatus.h>
#include <trans-dsl/utils/SeqInt.h>

TSL_NS_BEGIN

// 24 bytes
struct SchedSequential : SchedAction {
   OVERRIDE(exec(TransactionContext&)                      -> Status);
   OVERRIDE(handleEvent(TransactionContext&, Event const&) -> Status);
   OVERRIDE(stop(TransactionContext&, Status cause)        -> Status);
   OVERRIDE(kill(TransactionContext&, Status cause)        -> void);

private:
   auto forward(TransactionContext&) -> Status;
   auto getFinalStatus(Status status) -> Status;
   auto handleEvent_(TransactionContext& context, Event const& event) -> Status;

private:
   SchedAction* current = nullptr;
   Status stopCause{Result::SUCCESS};
   SeqInt index = 0;
   enum class State : uint8_t {
      INIT,
      WORKING,
      STOPPING,
      DONE
   };
   State state = State::INIT;

private:
   ABSTRACT(getNumOfActions() -> SeqInt);
   ABSTRACT(getNext(SeqInt index) -> SchedAction*);
};

TSL_NS_END

#endif //TRANS_DSL_2_SCHEDSEQUENTIAL_H
