#include "semaphore.ih"

inline void Semaphore::set(size_t available)
{
    d_nAvailable = available;
}
