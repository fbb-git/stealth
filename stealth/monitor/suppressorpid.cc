#include "monitor.ih"

int Monitor::suppressorPid()
try
{
    ifstream runFile;
    Errno::open(runFile, Lock::runFilename());

    int pid;
    runFile >> pid >> pid;

    return pid;
}
catch (...)
{
    return 0;        
}
