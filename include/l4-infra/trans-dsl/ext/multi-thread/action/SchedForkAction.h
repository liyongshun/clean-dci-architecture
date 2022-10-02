/*
 * SchedForkAction.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDFORKACTION_H_
#define SCHEDFORKACTION_H_

#include <l4-infra/trans-dsl/ext/multi-thread/concept/ActionThreadId.h>
#include <l4-infra/trans-dsl/sched/concept/SchedAction.h>

TSL_NS_BEGIN

struct ActionThread;

struct SchedForkAction : SchedAction
{
   OVERRIDE(cub::Status exec(TransactionContext&));
   OVERRIDE(cub::Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(cub::Status stop(TransactionContext&, cub::Status));
   OVERRIDE(void   kill(TransactionContext&, cub::Status));

private:
   USE_ROLE(ActionThread);

   ABSTRACT(ActionThreadId getThreadId() const);
};

TSL_NS_END

#endif /* SCHEDFORKACTION_H_ */
