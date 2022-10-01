//
// Created by Darwin Yuan on 2020/6/7.
//

#ifndef TRANS_DSL_2_SCHEDPROCEDURE_H
#define TRANS_DSL_2_SCHEDPROCEDURE_H

#include <trans-dsl/sched/domain/SchedAction.h>
#include <trans-dsl/sched/domain/RuntimeContext.h>

TSL_NS_BEGIN

struct TransactionContext;

// 40 bytes
struct SchedProcedure
   : private RuntimeContext
   , SchedAction {

   OVERRIDE(exec(TransactionContext&)                      -> Status);
   OVERRIDE(handleEvent(TransactionContext&, Event const&) -> Status);
   OVERRIDE(stop(TransactionContext&, Status)              -> Status);
   OVERRIDE(kill(TransactionContext&, Status)              -> void);

private:
   auto exec_(TransactionContext&) -> Status;
   auto handleEvent_(TransactionContext& context, Event const& event) -> Status;
   auto stop_(TransactionContext& context, Status cause) -> Status;
   auto workingStateCheck() -> void;

   auto gotoFinal(TransactionContext& context, Status status) -> Status;
   auto gotoDone(Status status) -> Status;

private:
   SchedAction* action = nullptr;
   enum class State : uint8_t {
      Idle,
      Working,
      Stopping,
      Final,
      Done
   };
   State state = State::Idle;

private:
   template<typename T>
   Status gotoState(TransactionContext& context, Status status);

private:
   ABSTRACT(getAction() -> SchedAction*);
   ABSTRACT(getFinalAction() -> SchedAction*);
   ABSTRACT(isProtected() const -> bool);
};

TSL_NS_END

#endif //TRANS_DSL_2_SCHEDPROCEDURE_H
