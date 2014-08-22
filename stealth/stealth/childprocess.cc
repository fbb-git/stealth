#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon();                // by Fork.

    doChores();    

    m1 << d_options.basename() << " (process " << getpid() << 
                                                    ") terminates" << endl;
    throw 0;
}
