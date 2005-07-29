#include "reporter.h2"

void Reporter::relax()
{
    close();
    Util::unlockRunFile();              // release the lock on an existing
                                        // run file.
}





