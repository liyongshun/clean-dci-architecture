/*
 * InvalidMsgSize.h
 *
 * Created on: Apr 23, 2013, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef INVALID_MSG_SIZE_H_
#define INVALID_MSG_SIZE_H_

#include <l4-infra/event/event.h>
#include <cstddef>

EV_NS_BEGIN

enum : size_t
{
    INVALID_MSG_SIZE = 0xFFFFFFFF
};

EV_NS_END

#endif /* INVALID_MSG_SIZE_H_ */
