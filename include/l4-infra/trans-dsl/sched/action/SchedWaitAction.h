/*
 * SchedWaitAction.h
 *
 * Created on: Apr 22, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCHEDWAITACTION_H_
#define SCHEDWAITACTION_H_

#include <l4-infra/event/concept/EventId.h>
#include <l4-infra/trans-dsl/sched/concept/SchedAction.h>

TSL_NS_BEGIN

struct SchedWaitAction : SchedAction
{
   OVERRIDE(cub::Status exec(TransactionContext&));
   OVERRIDE(cub::Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(cub::Status stop(TransactionContext&, const cub::Status));
   OVERRIDE(void kill(TransactionContext&, const cub::Status));

private:
   ABSTRACT(ev::EventId getEventId() const);
};

TSL_NS_END


#endif /* SCHEDWAITACTION_H_ */
