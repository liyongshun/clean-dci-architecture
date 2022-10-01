#ifndef INCL_CDA_INCLUDE_DEVELOPMENT_H_
#define INCL_CDA_INCLUDE_DEVELOPMENT_H_

#include "l4-infra/trans-dsl/TransactionDSL.h"
#include "l2-use-case/context/tdd/TddStartAction.h"
#include "l2-use-case/context/tdd/TddTestAction.h"
#include "l2-use-case/context/tdd/TddCodingAction.h"
#include "l2-use-case/context/tdd/TddRefactorAction.h"
#include "l2-use-case/context/tdd/TddEndAction.h"

CDA_NS_BEGIN

__def(TddTrans) __as
( __sequential(__call(TddStartAction)
              ,__call(TddTestAction)
              ,__asyn(TddCodingAction)
              ,__call(TddRefactorAction)
              ,__asyn(TddEndAction)
              )
);

CDA_NS_END

#endif
