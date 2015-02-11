#include "stealth.ih"

Stealth::Stealth(Options &options)
:
    d_options(options),                     // determine all options / runmode
    d_ipc(0),                               // Semaphores
    d_job(1),
{
    d_task.setMode(d_options.mode());
    d_pending.setMode(UNKNOWN);

//    d_fatal.rdbuf(new FatalBuffer(this));
//
//    LogUnit::init(d_fatal, d_options.syslogStruct(), 
//                    d_options.logName(), d_options.timestamp(),
//                    d_options.stdout());
}




