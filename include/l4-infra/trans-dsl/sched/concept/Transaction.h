/*
 * Transaction.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/event/event.h>
#include <l4-infra/trans-dsl/utils/StopCause.h>

FWD_DECL_EV(Event)

TSL_NS_BEGIN

DEFINE_ROLE(Transaction)
{
   ABSTRACT(cub::Status start());
   ABSTRACT(cub::Status handleEvent(const ev::Event&));
   ABSTRACT(cub::Status stop(const StopCause& = StopCause()));
   ABSTRACT(void   kill(const StopCause& = StopCause()));

   cub::Status startWithEvent(const ev::Event&);
};

TSL_NS_END

#endif /* TRANSACTION_H_ */
