//
// Created by Darwin Yuan on 2020/6/11.
//

#ifndef TRANS_DSL_2_SCHEDOPTIONAL_H
#define TRANS_DSL_2_SCHEDOPTIONAL_H

#include <trans-dsl/sched/domain/SchedAction.h>

TSL_NS_BEGIN

struct TransactionContext;

struct SchedOptional : SchedAction {
   OVERRIDE(exec(TransactionContext&)                      -> Status);
   OVERRIDE(handleEvent(TransactionContext&, Event const&) -> Status);
   OVERRIDE(stop(TransactionContext&, Status)              -> Status);
   OVERRIDE(kill(TransactionContext&, Status)              -> void);

private:
   SchedAction* action = nullptr;

private:
   ABSTRACT(getAction() -> SchedAction*);
   ABSTRACT(isTrue(TransactionContext&) -> bool);
};

TSL_NS_END

#endif //TRANS_DSL_2_SCHEDOPTIONAL_H
