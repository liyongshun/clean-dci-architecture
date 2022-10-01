#ifndef INCL_CDA_INCLUDE_TDDREFACTORACTION_H_
#define INCL_CDA_INCLUDE_TDDREFACTORACTION_H_

#include "l4-infra/cda.h"
#include "l4-infra/trans-dsl/action/SyncAction.h"

USING_TSL_NS

CDA_NS_BEGIN

struct TddRefactorAction : SyncAction
{
    OVERRIDE(Status exec(const TransactionInfo&));
};

CDA_NS_END

#endif
