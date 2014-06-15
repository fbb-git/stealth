#include "ipc.ih"

void IPC::writeRunFile(pid_t pid)
{
    string const &runFileName = Lock::runFilename();

    ofstream runFile(runFileName);

    m4 << "run file: " << runFileName << '\n';

    if (not (runFile << pid << endl))
    {
        Lock::unlinkRunFile();
        kill(SIGTERM, pid);
        fmsg << "could not write " << runFileName << endl;
    }
}
