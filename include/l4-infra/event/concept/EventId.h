/*
 * EventId.h
 *
 * Created on: Apr 21, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef EVENTID_H_
#define EVENTID_H_

#include <l4-infra/event/event.h>

EV_NS_BEGIN

typedef unsigned short EventId;

const EventId INVALID_EVENT_ID = 0xFFFF;

EV_NS_END

#endif /* EVENTID_H_ */
