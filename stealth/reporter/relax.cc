#include "reporter.ih"

bool Reporter::relax()
{
    flush();
    d_out.close();
    Lock::unlockRunFile();              // release the lock on an existing
                                        // run file.
    return d_continue;                  // inform the monitor about the 
                                        // need to continue
}





