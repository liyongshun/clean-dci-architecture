/*
 * RelativeTimer.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef RELATIVETIMER_H_
#define RELATIVETIMER_H_

#include <l4-infra/cub/base/Keywords.h>
#include <l4-infra/cub/base/Status.h>
#include <l4-infra/event/event.h>
#include <l4-infra/trans-dsl/sched/concept/TimerId.h>

FWD_DECL_EV(Event);

TSL_NS_BEGIN

struct TimerInfo;

struct RelativeTimer
{
   RelativeTimer(const TimerId timerId);

   cub::Status start(const TimerInfo&);
   void stop();

   bool matches(const ev::Event& event) const;

   virtual ~RelativeTimer() {}

private:
   const TimerId timerId;
   bool started;

private:
   ABSTRACT(bool isTimerEvent(const ev::Event&) const);
   ABSTRACT(cub::Status actualStartTimer(const TimerId, cub::U32 timerLen));
   ABSTRACT(void actualStopTimer(const TimerId));
   ABSTRACT(bool actualMatches(const ev::Event&, const TimerId) const);
};

TSL_NS_END

#endif /* RELATIVETIMER_H_ */
