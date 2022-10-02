#ifndef H38247538_297F_4A80_94D3_8B289888462A
#define H38247538_297F_4A80_94D3_8B289888462A

#include <arpa/inet.h>
#include <l4-infra/cub/base/BaseTypes.h>
#include <l4-infra/cub/cub.h>

CUB_NS_BEGIN

inline U8  hton(U8  v) { return v;         }
inline U16 hton(U16 v) { return htons(v);  }
inline U32 hton(U32 v) { return htonl(v);  }
inline U64 hton(U64 v) { return htonll(v); }

inline S8  hton(S8  v) { return v;         }
inline S16 hton(S16 v) { return htons(v);  }
inline S32 hton(S32 v) { return htonl(v);  }
inline S64 hton(S64 v) { return htonll(v); }

CUB_NS_END

#endif //CUB_BYTEORDER_H_H
