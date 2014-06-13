#include "reporter.ih"

void Reporter::ready()
{
    flush();
    d_out.flush();

cerr << "size at init: " << d_reinitSize << ", now: " <<
d_out.tellg() << endl;

    Lock::unlockRunFile();              // release the lock on an existing
                                        // run file.
}





