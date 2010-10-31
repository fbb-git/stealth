#include "monitor.ih"

// getPid() obtains the process-id from an existing lock-file. The file must
// exist and the pid stored in the lock-file must be the process-id of an
// existing Stealth program. This is verified by getPid()'s callers, when they
// send a signal to the corresponding process. by sending a fake SIGUSR1 signal
// to the obtained process-ID. If this fails, the lock-file is apparently
// stale. It is removed and an error message is issued.

size_t Monitor::getPid(string const &runFile)
{
    ifstream in(runFile.c_str());
    pid_t pid;

    if (!(in >> pid))
        fmsg << "Can't read `" << runFile << '\'' << endl;

    in.close();

    return pid;
}

    
