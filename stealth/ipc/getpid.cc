#include "ipc.ih"

// getPid() obtains the process-id from an existing run-file. The file must
// exist and the pid stored in the lock-file must be the process-id of an
// existing Stealth program. 

size_t IPC::getPid() const
{
    ifstream in;

    string const &runFile = d_options.runFile();

    Exception::open(in, runFile);

    pid_t pid;

    if (not (in >> pid))
        fmsg << "getPid: Can't read `" << runFile << '\'' << endl;

    return pid;
}


    



