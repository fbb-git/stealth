#include "util.h2"

// getPid() obtains the process-id from an existing lock-file. The file must
// exist and the pid stored in the lock-file must be the process-id of an
// existing Stealth program. This is verified by getPid()'s callers, when they
// send a signal to the corresponding process. by sending a fake SIGUSR1 signal
// to the obtained process-ID. If this fails, the lock-file is apparently
// stale. It is removed and an error message is issued.

unsigned Util::getPid(string const &runFilename)
{
    char const *runfile = runFilename.c_str();

    ifstream in(runfile);
    pid_t pid;

    if (!(in >> pid))
        exit(1, "Can't read `%s'", runfile);

    in.close();
//
//    if (kill(pid, SIGUSR1) != 0)
//    {
//        unlink(runfile);
//        exit(1, "Removing stale run-file `%s'", runfile);
//    }

    return pid;
}

    
