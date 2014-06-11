#include "ipc.ih"

bool IPC::signalSuppressor()
try
{
    ifstream runFile;
    Exception::open(runFile, Lock::runFilename());

    int pid;
    runFile >> pid >> pid;

    if (not runFile.good())
        return false;

    kill(SIGUSR1, pid);
    return true;
}
catch (...)
{
    return false;
}
