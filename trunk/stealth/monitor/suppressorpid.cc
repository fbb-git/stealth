#include "monitor.ih"

int Monitor::suppressorPid()
{
    ifstream runFile;
    Errno::open(runFile, Lock::runFilename());

    int pid;
    runFile >> pid >> pid;

    return pid;
}
