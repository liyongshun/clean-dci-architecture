/*
 * EventInfo.h
 *
 * Created on: Apr 23, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef EVENTINFO_H_
#define EVENTINFO_H_

#include <l4-infra/cub/base/Status.h>
#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/event/concept/EventId.h>
#include <cstddef>

EV_NS_BEGIN

DEFINE_ROLE(EventInfo)
{
   ABSTRACT(EventId getEventId() const);
   ABSTRACT(const void* getMsg() const);
   ABSTRACT(size_t getMsgSize() const);
   ABSTRACT(cub::Status updateEventId(const EventId) const);
};

EV_NS_END

#endif /* EVENTINFO_H_ */
