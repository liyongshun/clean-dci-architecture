/*
 * TransactionScheduler.h
 *
 * Created on: Jun 11, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONSCHEDULER_H_
#define TRANSACTIONSCHEDULER_H_

#include <l4-infra/cub/base/Status.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/trans-dsl/sched/concept/InstanceId.h>
#include <l4-infra/trans-dsl/sched/concept/Unknow.h>

FWD_DECL_EV(Event)

TSL_NS_BEGIN

struct ActionThread;
struct TransactionListener;
struct TimerInfo;
struct TransMutexScheduler;
struct UserContext;

DEFINE_ROLE(TransactionScheduler)
{
   ABSTRACT(cub::Status start(ActionThread&));
   ABSTRACT(cub::Status handleEvent(const ev::Event&));
   ABSTRACT(cub::Status stop(const cub::Status));
   ABSTRACT(void   kill(const cub::Status));

   ABSTRACT(void updateInstanceId(InstanceId iid));
   ABSTRACT(void updateTimerInfo(const TimerInfo&));
   ABSTRACT(void updateTransactionListener(TransactionListener&));
   ABSTRACT(void updateUserContext(Unknown*));
   ABSTRACT(void updateMutexScheduler(TransMutexScheduler&));
};

TSL_NS_END

#endif /* TRANSACTIONSCHEDULER_H_ */
