#include "reporter.ih"

void Reporter::relax()
{
    flush();
    d_out.close();
    Util::unlockRunFile();              // release the lock on an existing
                                        // run file.
}





