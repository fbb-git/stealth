#include "reporter.ih"

// This function is called from Monitor::control() at the beginning of the
// configuration processing loop. It (re)opens the report file and prepares it
// for the next run.

void Reporter::standby()
{
    if (!Lock::lockRunFile(Lock::NONBLOCKING))  // wait for the lock on an 
        return;                                 // existing run file. 
                                                // No run file: no lock

    d_out.open(d_name.c_str(), ios::out | ios::ate | ios::in);
    if (!d_out)
    {
        d_out.clear();
        Exception::open(d_out, d_name, ios::out | ios::in | ios::trunc);    
    }

    reinit();
}





