#include "monitor.ih"

// Called by stealth --lock ...
//
void Monitor::lock(string const &runfile)
{
    size_t pid;

    pid = getPid(runfile);
    imsg << "Trying to lock " << runfile << " of process " << pid << endl;

    Lock::setRunFilename(runfile);
    Lock::lockRunFile(Lock::BLOCKING);      // Obtain the lock on the runfile
                                    
    signalStealth(SIGUSR1, "SIGUSR1", runfile); // exits, and releases the
                                                // lock.
}
