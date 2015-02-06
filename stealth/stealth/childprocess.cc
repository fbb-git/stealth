#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon("/tmp/serr", "/tmp/serr");                // by Fork.
//    prepareDaemon();                // by Fork.


                                    // start the ipc interface thread
    thread interface(startIpcInterface, this);

    doChores();    

    m1 << d_options.basename() << " (process " << getpid() << 
                                                    ") terminates" << endl;

    interface.join();               // wait for the interface thread to finish

    throw 0;
}
