/*
 * Action.h
 *
 * Created on: Apr 24, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef ACTION_H_
#define ACTION_H_

#include <l4-infra/event/event.h>
#include <l4-infra/trans-dsl/action/SyncAction.h>

FWD_DECL_EV(Event);

TSL_NS_BEGIN

struct Action : SyncAction
{
    ABSTRACT(cub::Status handleEvent(const TransactionInfo&, const ev::Event&));
    ABSTRACT(void   kill(const TransactionInfo&, const cub::Status cause));
};

TSL_NS_END

#endif /* ACTION_H_ */
