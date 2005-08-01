#include "util.h2"

int Util::suppressorPid()
{
    ifstream runFile(s_runFilename.c_str());

    int pid;
    runFile >> pid >> pid;

    return pid;
}
