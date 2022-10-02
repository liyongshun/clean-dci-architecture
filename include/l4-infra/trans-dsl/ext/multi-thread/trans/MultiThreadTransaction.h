/*
 * MultiThreadTransaction.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef MULTITHREADTRANSACTION_H_
#define MULTITHREADTRANSACTION_H_

#include <l4-infra/trans-dsl/ext/multi-thread/trans/MultiThreadTransactionScheduler.h>
#include <l4-infra/trans-dsl/sched/trans/SchedTransaction.h>

TSL_NS_BEGIN

typedef SchedulerBasedTransaction<MultiThreadTransactionScheduler> MultiThreadTransaction;

TSL_NS_END

#endif /* MULTITHREADTRANSACTION_H_ */
