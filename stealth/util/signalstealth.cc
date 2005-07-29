#include "util.h2"

// getPid() obtains the process-id from an existing lock-file. The file must
// exist and the pid stored in the lock-file must be the process-id of an
// existing Stealth program. This is verified by sending a signal to the
// corresponding process. If this fails, the lock-file is apparently stale. It
// is removed and an error message is issued.

// The following signals are used (and processed by Scanner::processSignal())
// SIGTERM: terminate stealth
// SIGHUP:  rerun stealth
// SIGUSR1: suppress stealth from starting a new run
// SIGUSR2: resume normal actions. 

void Util::signalStealth(int signum, char const *signame, 
                                     string const &filename)
{
    unsigned pid = getPid(filename);

    dout("Sending " << signame << " to process " << pid);

    if (kill(pid, signum))
    {
        unlink(filename.c_str());
        exit(1, "Can't send %s to process `%u',\n"
                "removing stale run-file `%s'.",
                signame,
                pid,
                filename.c_str());
    }

    dout(signame << " sent");
    throw OK; //    ::exit(0);                              // done
}
