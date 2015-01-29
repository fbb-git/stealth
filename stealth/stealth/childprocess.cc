#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon();                // by Fork.

                                    // start the communication thread
    thread comm(startThread<&Stealth::communicator>, this);   

    doChores();    

    m1 << d_options.basename() << " (process " << getpid() << 
                                                    ") terminates" << endl;

    comm.join();                    // wait for the comm. thread to finish

    throw 0;
}
