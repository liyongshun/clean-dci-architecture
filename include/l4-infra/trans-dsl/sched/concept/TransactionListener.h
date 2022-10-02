/*
 * TransactionListener.h
 *
 * Created on: May 28, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONLISTENER_H_
#define TRANSACTIONLISTENER_H_

#include <l4-infra/cub/base/Default.h>
#include <l4-infra/cub/base/Status.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/event/event.h>
#include <l4-infra/trans-dsl/sched/concept/ActionId.h>


FWD_DECL_EV(Event)

TSL_NS_BEGIN

DEFINE_ROLE(TransactionListener)
{
   DEFAULT(void, onActionStarting(const ActionId));
   DEFAULT(void, onActionStarted(const ActionId));
   DEFAULT(void, onActionEventConsumed(const ActionId, const ev::Event&));
   DEFAULT(void, onActionDone(const ActionId, const cub::Status));

   DEFAULT(void, onActionStartStopping(const ActionId, const cub::Status));
   DEFAULT(void, onActionStoppingStarted(const ActionId));
   DEFAULT(void, onStoppingEventConsumed(const ActionId, const ev::Event&));
   DEFAULT(void, onActionStopped(const ActionId, const cub::Status));

   DEFAULT(void, onActionKilled(const ActionId, const cub::Status));
};

TransactionListener& getNilTransactionListener();

TSL_NS_END

#endif /* TRANSACTIONLISTENER_H_ */
