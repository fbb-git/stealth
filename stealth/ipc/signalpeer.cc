#include "ipc.ih"

bool IPC::signalPeer(int signum)
{
    size_t pid = getPid();    // get the pid of the process to signal 

    imsg << "Sending " << s_signame.find(signum)->second << " to process " << 
            pid << endl;

    // When suppressing (SIGUSR1) we must add this process' ID to the runfile
    // so the suppressed stealth process can signal back that it has completed
    // its suppression tasks. Note that this process still has the lock, which
    // must be removed first before the suppressed stealth process may
    // continue. 

    if (signum == SIGUSR1)          // --suppress
        suppress(pid);


    sendSignal(signum, pid);    // signal the running stealth, but we
                                // still have the lock. It will disappear
                                // when  this process terminates, so below
                                // it must be explicitly removed when
                                // we're suppressing, and are waiting for
                                // the reply signal


    if (signum == SIGUSR1)              // when suppressing (SIGUSR1)
        suppressing(pid);

    return true;
}


