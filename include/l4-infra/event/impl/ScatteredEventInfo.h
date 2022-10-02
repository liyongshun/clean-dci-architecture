/*
 * ScatteredEventInfo.h
 *
 * Created on: Apr 23, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef SCATTEREDEVENTINFO_H_
#define SCATTEREDEVENTINFO_H_

#include <l4-infra/event/impl/BaseEventInfo.h>

EV_NS_BEGIN

struct ScatteredEventInfo : BaseEventInfo
{
   ScatteredEventInfo(const EventId eventId, const void* const msg);

   OVERRIDE(const void* getMsg() const);
   OVERRIDE(size_t getMsgSize() const);

private:
   const void* const  msg;
};

EV_NS_END

#endif /* SCATTEREDEVENTINFO_H_ */
