/*
 * TransactionContext.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONCONTEXT_H_
#define TRANSACTIONCONTEXT_H_

#include <l4-infra/cub/base/Status.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/trans-dsl/sched/concept/Unknow.h>
#include <l4-infra/trans-dsl/tsl.h>

TSL_NS_BEGIN

struct TransactionInfo;
struct TransactionListener;
struct TransactionMode;

struct TransactionContext : Unknown
{
   HAS_ROLE(TransactionInfo);
   HAS_ROLE(TransactionListener);
   HAS_ROLE(TransactionMode);
};

TSL_NS_END

#endif /* TRANSACTIONCONTEXT_H_ */
