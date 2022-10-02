/*
 * WithIdHelper.h
 *
 * Created on: May 28, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef WITHIDHELPER_H_
#define WITHIDHELPER_H_

#include <l4-infra/trans-dsl/sched/action/SchedWithIdAction.h>

TSL_NS_BEGIN

namespace details
{
   template <ActionId I_ACTION_ID, typename T_ACTION>
   struct WITH_ID__ : SchedWithIdAction
   {
   private:
      OVERRIDE(ActionId getActionId() const)
      {
         return I_ACTION_ID;
      }

      IMPL_ROLE_WITH_VAR(SchedAction, T_ACTION);
   };
};

TSL_NS_END

///////////////////////////////////////////////////////////////
#define __with_id(...) TSL_NS::details::WITH_ID__< __VA_ARGS__ >

///////////////////////////////////////////////////////////////

#endif /* WITHIDHELPER_H_ */
