#include "reporter.ih"

// This function is called from Monitor::control() at the beginning of the
// configuration processing loop. It (re)opens the report file and prepares it
// for the next run.

void Reporter::standby()
{
    if (!Util::lockRunFile(Util::NONBLOCKING))  // wait for the lock on an 
        return;                                 // existing run file. 
                                                // No run file: no lock

    d_out.open(d_name.c_str(), ios::out | ios::ate | ios::in);
    if (!d_out.is_open())
    {
        d_out.clear();
        d_out.open(d_name.c_str(), ios::out | ios::in | ios::trunc);    
                                                        // open if construction
    }                                                   // fails: new file

    if (!d_out.is_open())
        throw Errno("Can't open ") << insertable << d_name << throwable;

    reinit();
}





