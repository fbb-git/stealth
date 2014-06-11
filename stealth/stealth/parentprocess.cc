#include "stealth.ih"

void Stealth::parentProcess()
{
    ofstream runFile(Lock::runFilename());

    cerr << "Run file = " << Lock::runFilename() << '\n';

    if (not (runFile << pid() << endl))
    {
        Lock::unlinkRunFile();
        kill(SIGTERM, pid());
        fmsg << "could not write " << d_options.runFile() << endl;
    }

    cerr << "wrote " << pid() << " on " << Lock::runFilename()  << endl;
}

