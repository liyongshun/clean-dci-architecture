/*
 * RuntimeContextInfo.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef RUNTIMECONTEXTINFO_H_
#define RUNTIMECONTEXTINFO_H_

#include <l4-infra/cub/dci/InterfaceDef.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/trans-dsl/tsl.h>

TSL_NS_BEGIN

struct RuntimeContext;

UNKNOWN_INTERFACE(RuntimeContextInfo, 973432232)
{
   ABSTRACT(void setRuntimeContext(RuntimeContext&));
   ABSTRACT(RuntimeContext* getRuntimeContext() const);
};

TSL_NS_END

#endif /* RUNTIMECONTEXTINFO_H_ */
