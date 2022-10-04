//
// Created by Darwin Yuan on 2020/6/7.
//

#ifndef TRANS_DSL_2_EVENT_TSL_H
#define TRANS_DSL_2_EVENT_TSL_H

#include <event/event_ns.h>
#include <trans-dsl/tsl_ns.h>
#include <event/concept/Event.h>

FWD_DECL_EV(Event);

TSL_NS_BEGIN

//struct Event : EV_NS::Event {};
using Event = EV_NS::Event;

TSL_NS_END

#endif //TRANS_DSL_2_EVENT_TSL_H
