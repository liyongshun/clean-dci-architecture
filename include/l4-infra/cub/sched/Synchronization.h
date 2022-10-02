#ifndef H671141B2_B247_440B_8E83_476558110FE5
#define H671141B2_B247_440B_8E83_476558110FE5

#include <l4-infra/cub/cub.h>
#include <mutex>

CUB_NS_BEGIN

struct AutoLock
{
    AutoLock(std::mutex& m)
    : locker(m)
    {
    }

    void setUnLock()
    {
        locked = false;
    }

    bool isLocked() const
    {
        return locked;
    }

    std::unique_lock<std::mutex>& getLocker()
    {
        return locker;
    }

private:
    bool locked{true};
    std::unique_lock<std::mutex> locker;
};

#define LOCKER(M) auto_##M
#define SYNCHRONIZED(M)  for(::CUB_NS::AutoLock LOCKER(M)(M); LOCKER(M).isLocked(); LOCKER(M).setUnLock())

CUB_NS_END

#endif
