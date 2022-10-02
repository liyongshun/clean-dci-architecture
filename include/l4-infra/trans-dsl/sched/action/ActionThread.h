/*
 * ActionThread.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef ACTIONTHREAD_H_
#define ACTIONTHREAD_H_

#include <l4-infra/trans-dsl/sched/concept/SchedAction.h>
#include <l4-infra/trans-dsl/utils/DeclState.h>
#include <l4-infra/trans-dsl/utils/SimpleRuntimeContext.h>

TSL_NS_BEGIN

struct ActionThread : private SimpleRuntimeContext, SchedAction
{
   ActionThread();

   OVERRIDE(cub::Status exec(TransactionContext&));
   OVERRIDE(cub::Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(cub::Status stop(TransactionContext&, const cub::Status));
   OVERRIDE(void   kill(TransactionContext&, const cub::Status));

   using SimpleRuntimeContext::getStatus;

   bool isWorking() const;

private:
   struct State;
   State* state;

   struct WorkingState;

private:
   __DECL_STATE(Idle);
   __DECL_STATE(Working);
   __DECL_STATE(Stopping);
   __DECL_STATE(Done);

   struct AutoSwitch;

private:
   USE_ROLE(SchedAction);
};

TSL_NS_END

#endif /* ACTIONTHREAD_H_ */
