#include "wait11.ih"

void Wait11::waitFor(size_t seconds, bool doM2)
{
    d_signaled = false;

    while (true)
    {
        unique_lock<mutex> lock(d_mutex);    // get the lock

        if (d_condition.wait_for(lock, chrono::seconds(seconds)) ==
                            std::cv_status::timeout)
        {
            if (doM2)
                m2 << "timeout after " << seconds << " seconds" << endl;
            return;
        }

        if (d_signaled)
        {
            if (doM2)
                m2 << "received signal: done waiting" << endl;
            return;
        }
    }
}
