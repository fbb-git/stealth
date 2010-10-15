#include "util.ih"

// Called by stealth --lock ...
//
void Util::lock(string const &runfile)
{
    size_t pid;

    pid = getPid(runfile);
    debug() << "Trying to lock " << runfile << " of process " << pid << "\n";

    s_runFilename = runfile;
    lockRunFile(BLOCKING);          // Obtain the lock on the runfile
                                    
    signalStealth(SIGUSR1, "SIGUSR1", runfile); // exits, and releases the
                                                // lock.
}
