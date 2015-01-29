#include "wait11.ih"

void Wait11::notify()
{
    lock_guard<mutex> lock(d_mutex);
    d_signaled = true;
    d_condition.notify_one();
}
