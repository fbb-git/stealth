#include "ipc.ih"

// daemonPid() obtains the process-id from an existing run-file. The file must
// exist and the pid stored in the lock-file must be the process-id of an
// existing Stealth program. 

void IPC::readDaemonPid()
{
    ifstream in;

    string const &runFile = d_options.runFile();

    Exception::open(in, runFile);

    pid_t pid;

    if (not (in >> pid))
        fmsg << "daemonPid: Can't read `" << runFile << '\'' << endl;

    d_daemonPid = pid;
}


    



