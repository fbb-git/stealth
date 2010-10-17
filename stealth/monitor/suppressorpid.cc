#include "monitor.ih"

int Monitor::suppressorPid()
{
    ifstream runFile;
    Msg::open(runFile, Lock::runFilename());

    int pid;
    runFile >> pid >> pid;

    return pid;
}
