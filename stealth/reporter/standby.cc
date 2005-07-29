#include "reporter.h2"

void Reporter::standby()
{
    if (!Util::lockRunFile(Util::NONBLOCKING))  // wait for the lock on an 
        return;                                 // existing run file. 
                                                // No run file: no lock

    open(d_name.c_str(), ios::out | ios::ate | ios::in);
    if (!is_open())
    {
        clear();
        open(d_name.c_str(), ios::out | ios::in | ios::trunc);    // open if 
    }                                                   // construction fails:
                                                        // new file
    if (!is_open())
        throw Errno((s_msg = "Can't open " +  d_name).c_str());

    reinit();
}





