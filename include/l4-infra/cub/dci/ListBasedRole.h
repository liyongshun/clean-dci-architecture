#ifndef INCLUDE_CUB_DCI_LISTBASEDROLE_H_
#define INCLUDE_CUB_DCI_LISTBASEDROLE_H_

#include <l4-infra/cub/dci/Role.h>
#include <l4-infra/cub/repo/list/ListElem.h>

#define DEFINE_LIST_BASED_ROLE(role) \
   DEFINE_ROLE(role) EXTENDS(CUB_NS::ListElem<role>)

#endif /* INCLUDE_CUB_DCI_LISTBASEDROLE_H_ */
