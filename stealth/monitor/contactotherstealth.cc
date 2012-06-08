#include "monitor.ih"

void Monitor::contactOtherStealth()
{
    if (d_arg.option(0, "reload"))
        signalStealth(SIGCHLD, "SIGCHLD", d_arg[0]);// signalStealth calls
                                                    // end the current process
    if (d_arg.option(0, "rerun"))
        signalStealth(SIGHUP, "SIGHUP", d_arg[0]);

    if (d_arg.option(0, "terminate"))
        signalStealth(SIGTERM, "SIGTERM", d_arg[0]);  

    if (d_arg.option(0, "suppress"))
        lock(d_arg[0]);                             // lock locally, let the
                                                    // integrity wait, exits
    if (d_arg.option(0, "resume"))
        signalStealth(SIGUSR2, "SIGUSR2", d_arg[0]);  
}


