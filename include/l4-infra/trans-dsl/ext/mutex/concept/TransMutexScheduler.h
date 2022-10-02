/*
 * TransMutexScheduler.h
 *
 * Created on: Aug 7, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSMUTEXSCHEDULER_H_
#define TRANSMUTEXSCHEDULER_H_

#include <l4-infra/cub/base/Status.h>
#include <l4-infra/cub/dci/InterfaceDef.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/trans-dsl/ext/mutex/concept/TransMutextId.h>

TSL_NS_BEGIN

UNKNOWN_INTERFACE(TransMutexScheduler, 34427421)
{
   ABSTRACT(cub::Status lock(TransMutexId));
   ABSTRACT(void unlock(TransMutexId));
};

TSL_NS_END

#endif /* TRANSMUTEXSCHEDULER_H_ */
