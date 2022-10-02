/*
 * SimpleTransactionInfo.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SIMPLETRANSACTIONINFO_H_
#define SIMPLETRANSACTIONINFO_H_

#include <l4-infra/trans-dsl/sched/concept/TransactionInfo.h>

TSL_NS_BEGIN

struct RuntimeContextInfo;

struct SimpleTransactionInfo : TransactionInfo
{
   explicit SimpleTransactionInfo(InstanceId iid = 0);

   OVERRIDE(InstanceId getInstanceId() const);
   OVERRIDE(cub::Status getStatus() const);
   OVERRIDE(Unknown* getUserContext() const);

   void updateUserContext(Unknown*);
   void updateInstanceId(InstanceId iid);

private:
   InstanceId iid = 0;
   Unknown* userContext = nullptr;

private:
   USE_ROLE(RuntimeContextInfo);
};

TSL_NS_END

#endif /* SIMPLETRANSACTIONINFO_H_ */
