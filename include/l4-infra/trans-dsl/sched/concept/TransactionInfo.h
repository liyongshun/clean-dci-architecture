/*
 * TransactionInfo.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTIONINFO_H_
#define TRANSACTIONINFO_H_

#include <l4-infra/cub/base/Status.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/trans-dsl/sched/concept/InstanceId.h>
#include <l4-infra/trans-dsl/sched/concept/Unknow.h>

TSL_NS_BEGIN

DEFINE_ROLE(TransactionInfo)
{
   ABSTRACT(InstanceId getInstanceId() const);
   ABSTRACT(cub::Status getStatus() const);
   ABSTRACT(Unknown* getUserContext() const);

   template <typename ROLE>
   ROLE* toRole() const
   {
      return dynamic_cast<ROLE*>(getUserContext());
   }
};

TSL_NS_END

#endif /* TRANSACTIONINFO_H_ */
