//
// Created by Darwin Yuan on 2020/6/10.
//

#ifndef TRANS_DSL_2_SIMPLEEVENTINFO_H
#define TRANS_DSL_2_SIMPLEEVENTINFO_H

#include <event/concept/EventInfo.h>

EV_NS_BEGIN

struct SimpleEventInfo : EventInfo
{
   explicit SimpleEventInfo(const EventId eventId)
      : EventInfo(eventId) {}

   OVERRIDE(getMsg() const -> const void*) { return nullptr; }
   OVERRIDE(getMsgSize() const -> size_t) { return 0; }
   OVERRIDE(getSequenceNum() const             -> uint32_t) { return 0xFFFF'FFFF; }
};

EV_NS_END

#endif //TRANS_DSL_2_SIMPLEEVENTINFO_H
