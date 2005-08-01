#include "util.h2"

// Called by stealth --lock ...
//
void Util::lock(string const &runfile)
{
    unsigned pid;

    pid = getPid(runfile);
    dout("Trying to lock " << runfile << " of process " << pid);

    s_runFilename = runfile;
    lockRunFile(BLOCKING);          // Obtain the lock on the runfile
                                    
    signalStealth(SIGUSR1, "SIGUSR1", runfile); // exits, and releases the
                                                // lock.
}
