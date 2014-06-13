#include "reporter.ih"

void Reporter::ready()
{
    flush();
    d_out.flush();
    Lock::unlockRunFile();              // release the lock on an existing
                                        // run file.
}





