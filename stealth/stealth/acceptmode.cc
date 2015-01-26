#include "stealth.ih"

string Stealth::acceptMode(Mode mode)
{
    d_run.setMode(mode);
    return "";
}
