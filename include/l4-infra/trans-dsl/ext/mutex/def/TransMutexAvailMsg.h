/*
 * TransMutexAvailMsg.h
 *
 * Created on: Aug 7, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSMUTEXAVAILMSG_H_
#define TRANSMUTEXAVAILMSG_H_

#include <l4-infra/event/concept/EventId.h>
#include <l4-infra/trans-dsl/ext/mutex/concept/TransMutextId.h>

TSL_NS_BEGIN

const ev::EventId EV_MUTEX_UNLOCK = 0xFFFD;

struct TransMutexAvailMsg
{
   TransMutexAvailMsg(TransMutexId id)
      : id(id)
   {}

   bool matches(TransMutexId id) const
   {
      return this->id == id;
   }

private:
   TransMutexId id;
};

TSL_NS_END


#endif /* TRANSMUTEXAVAILMSG_H_ */
