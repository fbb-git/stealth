#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon();                // by Fork.

    thread comm(comThread, this);   // start the communication thread

    doChores();    

    m1 << d_options.basename() << " (process " << getpid() << 
                                                    ") terminates" << endl;

    comm.join();                    // wait for the comm. thread to finish

    throw 0;
}
