#include "stealth.ih"

Stealth::Stealth()
:
    d_options(Options::instance()),         // determine all options / runmode
    d_command(1),
    d_remote(0)
{
    d_task.setMode(d_options.mode());
}




