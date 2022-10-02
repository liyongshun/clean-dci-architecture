/*
 * InstanceId.h
 *
 * Created on: Apr 21, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef INSTANCEID_H_
#define INSTANCEID_H_

#include <l4-infra/trans-dsl/tsl.h>

TSL_NS_BEGIN

// XXX: should be as wide as pointer.
typedef unsigned long InstanceId;

TSL_NS_END

#endif /* INSTANCEID_H_ */
