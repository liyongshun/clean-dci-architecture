/*
 * SimpleEventInfo.h
 *
 * Created on: Apr 23, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SIMPLEEVENTINFO_H_
#define SIMPLEEVENTINFO_H_

#include <l4-infra/event/impl/BaseEventInfo.h>

EV_NS_BEGIN

struct SimpleEventInfo : BaseEventInfo
{
   explicit SimpleEventInfo(const EventId eventId);

   OVERRIDE(const void* getMsg() const);
   OVERRIDE(size_t getMsgSize() const);
};

EV_NS_END

#endif /* SIMPLEEVENTINFO_H_ */
