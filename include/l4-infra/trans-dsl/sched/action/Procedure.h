/*
 * Procedure.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef PROCEDURE_H_
#define PROCEDURE_H_

#include <l4-infra/trans-dsl/sched/concept/SchedAction.h>
#include <l4-infra/trans-dsl/utils/DeclState.h>
#include <l4-infra/trans-dsl/utils/SimpleRuntimeContext.h>

TSL_NS_BEGIN

struct FinalAction;

struct Procedure : private SimpleRuntimeContext, SchedAction
{
   Procedure();

   OVERRIDE(cub::Status exec(TransactionContext&));
   OVERRIDE(cub::Status handleEvent(TransactionContext&, const ev::Event&));
   OVERRIDE(cub::Status stop(TransactionContext&, cub::Status));
   OVERRIDE(void   kill(TransactionContext&, cub::Status));

private:
   OVERRIDE(bool shouldReportParent() const);

private:
   void doKill(FinalAction&, TransactionContext&, cub::Status);
   cub::Status getFinalStatus() const;

private:
   struct State;
   State* state;

   struct AutoSwitch;

private:
   __DECL_STATE(Idle);
   __DECL_STATE(Working);
   __DECL_STATE(Stopping);
   __DECL_STATE(Final);
   __DECL_STATE(Done);

   struct WorkingState;

private:
   USE_ROLE(SchedAction);
   USE_ROLE(FinalAction);
   ABSTRACT(bool isProtected() const);
};

TSL_NS_END


#endif /* PROCEDURE_H_ */
