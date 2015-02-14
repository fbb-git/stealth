#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon("/tmp/serr", "/tmp/serr");                // by Fork.
//    prepareDaemon();                // by Fork.

                                    // start the ipc interface thread
    thread(startThread, &Stealth::ipcInterface, this).detach();

    doTasks();    

    m1 << d_options.basename() << " (process " << getpid() << 
                                                    ") terminates" << endl;
    throw 0;
}
