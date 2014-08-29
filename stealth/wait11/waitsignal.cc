#include "wait11.ih"

void Wait11::waitSignal(bool doM2)
{
    unique_lock<mutex> lock(d_mutex);    // get the lock

    d_signaled = false;

    if (doM2)
        m2 << "waiting..." << endl;

    while (not d_signaled)
        d_condition.wait(lock);
}
