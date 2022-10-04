#ifndef INCL_CDA_INCLUDE_DEVELOPMENT_H_
#define INCL_CDA_INCLUDE_DEVELOPMENT_H_

#include "trans-dsl/trans-dsl.h"
#include "l2-use-case/context/tdd/TddStartAction.h"
#include "l2-use-case/context/tdd/TddTestAction.h"
#include "l2-use-case/context/tdd/TddCodingAction.h"
#include "l2-use-case/context/tdd/TddRefactorAction.h"
#include "l2-use-case/context/tdd/TddEndAction.h"

USING_TSL_NS

CDA_NS_BEGIN

using TddTrans = __transaction
( __sequential
    ( __sync(TddStartAction)
    , __sync(TddTestAction)
    , __asyn(TddCodingAction)
    , __sync(TddRefactorAction)
    , __asyn(TddEndAction))
);

CDA_NS_END

#endif
