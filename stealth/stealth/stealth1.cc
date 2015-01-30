#include "stealth.ih"

Stealth::Stealth()
:
    d_options(Options::instance()),         // determine all options / runmode
    d_ipc(0),
    d_processor(1),
    d_result(0)
{
    d_task.setMode(d_options.mode());
}




