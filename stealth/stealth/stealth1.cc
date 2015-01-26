#include "stealth.ih"

Stealth::Stealth()
:
    d_options(Options::instance()),         // determine all options / runmode
    d_communicate(0),
    d_chore(0)
{
    d_run.setMode(d_options.mode());
}




