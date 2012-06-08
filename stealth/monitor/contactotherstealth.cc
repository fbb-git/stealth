#include "monitor.ih"

void Monitor::contactOtherStealth()
{
    if (d_arg.option(0, "reload"))
        signalStealth(SIGCHLD, "SIGCHLD", arg[0]);  // signalStealth calls
                                                    // end the current process
    if (d_arg.option(0, "rerun"))
        signalStealth(SIGHUP, "SIGHUP", arg[0]);

    if (d_arg.option(0, "terminate"))
        signalStealth(SIGTERM, "SIGTERM", arg[0]);  

    if (d_arg.option(0, "suppress"))
        lock(arg[0]);                               // lock locally, let the
                                                    // integrity wait, exits
    if (d_arg.option(0, "resume"))
        signalStealth(SIGUSR2, "SIGUSR2", arg[0]);  
}


