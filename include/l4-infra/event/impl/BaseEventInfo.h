/*
 * BaseEventInfo.h
 *
 * Created on: Apr 23, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef BASEEVENTINFO_H_
#define BASEEVENTINFO_H_

#include <l4-infra/event/concept/EventInfo.h>

EV_NS_BEGIN

struct BaseEventInfo : EventInfo
{
   explicit BaseEventInfo(const EventId eventId);

   OVERRIDE(EventId getEventId() const);
   OVERRIDE(cub::Status updateEventId(const EventId id) const);

private:
   mutable EventId      eventId;
};

EV_NS_END

#endif /* BASEEVENTINFO_H_ */
