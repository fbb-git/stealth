#include "stealth.ih"

int Stealth::suppressorPid()
try
{
    ifstream runFile;
    Exception::open(runFile, Lock::runFilename());

    int pid;
    runFile >> pid >> pid;

    return pid;
}
catch (...)
{
    return 0;        
}
