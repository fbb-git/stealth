#include "stealth.ih"

Stealth::Stealth()
:
    d_options(Options::instance())
{
    d_run.setMode(d_options.mode());
}




