#ifndef INCLUDE_EVENT_EVENT_H_
#define INCLUDE_EVENT_EVENT_H_

#define EV_NS ev
#define EV_NS_BEGIN namespace EV_NS {
#define EV_NS_END   }
#define USING_EV_NS using namespace EV_NS;
#define FWD_DECL_EV(type) namespace EV_NS { struct type; }

#endif /* INCLUDE_EVENT_EVENT_H_ */
