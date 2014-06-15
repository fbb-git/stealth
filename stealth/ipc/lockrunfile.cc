#include "ipc.ih"

void IPC::lockRunFile() const
{
    size_t pid = getPid();

    string const &runFile = Options::instance().runFile();

    m2 << "Trying to lock " << runFile << " of process " << pid << endl;

    Lock::setRunFilename(runFile);
    Lock::lockRunFile(Lock::BLOCKING);      // Obtain the lock on the runfile
}

