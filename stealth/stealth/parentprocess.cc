#include "stealth.ih"

void Stealth::parentProcess()
{
    ofstream runFile(Lock::runFilename());
    if (not (runFile << pid() << endl))
    {
        Lock::unlinkRunFile();
        kill(SIGTERM, pid());
        fmsg << "could not write " << d_options.runFile() << endl;
    }
}

