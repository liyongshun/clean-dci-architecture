#ifndef INCLUDE_L4_INFRA_CUB_DCI_FRACTAL_H_
#define INCLUDE_L4_INFRA_CUB_DCI_FRACTAL_H_

#include "cub/dci/Role.h"

namespace details
{
    struct Interface
    {
        virtual ~Interface() {}
    };

    struct Behavior
    {
        virtual ~Behavior() {}
    };

    struct Model
    {
        virtual ~Model() {}
    };
}

#define DEF_I(interface) struct interface : ::details::Interface
#define IMPL_I(interface) IMPL_ROLE(interface)
#define I(interface) ROLE(interface)
#define USE_I(interface) USE_ROLE(interface)
#define HAS_I(interface) USE_I(interface)

#define DEF_B(behavior) struct behavior : ::details::Behavior
#define IMPL_B(behavior) IMPL_ROLE(behavior)
#define B(behavior) ROLE(behavior)
#define USE_B(behavior) USE_ROLE(behavior)
#define HAS_B(behavior) USE_B(behavior)

#define DEF_M(model) struct model : ::details::Model
#define IMPL_M(model) IMPL_ROLE(model)
#define M(model) ROLE(model)
#define USE_M(model) USE_ROLE(model)
#define HAS_M(model) USE_M(model)

#endif /* INCLUDE_L4_INFRA_CUB_DCI_FRACTAL_H_ */

