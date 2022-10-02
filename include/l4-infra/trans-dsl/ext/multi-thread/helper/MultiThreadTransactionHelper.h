/*
 * MultiThreadTransactionHelper.h
 *
 * Created on: Apr 23, 2013
 *     author: Darwin Yuan
 *
 * Copyright 2013 ThoughtWorks, All Rights Reserved.
 *
 */ 

#ifndef MULTITHREADTRANSACTIONHELPER_H_
#define MULTITHREADTRANSACTIONHELPER_H_

#include <l4-infra/trans-dsl/ext/multi-thread/helper/ThreadHelper.h>
#include <l4-infra/trans-dsl/ext/multi-thread/trans/MultiThreadTransaction.h>
#include <l4-infra/trans-dsl/sched/helper/ProcedureHelper.h>

TSL_NS_BEGIN

namespace details
{
   template<typename T_ACTION>
   struct MULTI_THREAD_TRANSACTION__: MultiThreadTransaction
   {
      explicit MULTI_THREAD_TRANSACTION__(const InstanceId iid = 0)
          : MultiThreadTransaction(iid) {}

   private:
      typedef THREAD__<T_ACTION> Thread;
      IMPL_ROLE_WITH_VAR(ActionThread, Thread);
   };
}

TSL_NS_END

///////////////////////////////////////////////////////////////////////
#define __mt_transaction(...) \
     TSL_NS::details::MULTI_THREAD_TRANSACTION__< TSL_NS::details::PROCEDURE__< __VA_ARGS__ > >

#define __def_mt_transaction(...) \
     typedef __mt_transaction(__VA_ARGS__)

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define __prot_mt_transaction(...) \
     TSL_NS::details::MULTI_THREAD_TRANSACTION__< TSL_NS::details::PROTECTED_PROC__<__VA_ARGS__ > >

#define __def_prot_mt_transaction(...) \
     typedef __prot_mt_transaction(__VA_ARGS__)

#endif /* MULTITHREADTRANSACTIONHELPER_H_ */
