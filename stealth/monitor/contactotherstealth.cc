#include "monitor.ih"

void Monitor::contactOtherStealth()
{
    Arg &arg = Arg::instance();

    if (arg.option(0, "rerun"))
        signalStealth(SIGHUP, "SIGHUP", arg[0]);    // all signalStealth calls
                                                    // end the current process

    if (arg.option(0, "terminate"))
        signalStealth(SIGTERM, "SIGTERM", arg[0]);  

    if (arg.option(0, "suppress"))
        lock(arg[0]);                               // lock locally, let the
                                                    // integrity wait, exits
    if (arg.option(0, "resume"))
        signalStealth(SIGUSR2, "SIGUSR2", arg[0]);  
}


