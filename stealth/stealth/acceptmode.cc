#include "stealth.ih"

string Stealth::acceptMode(Mode mode)
{
    d_task.setMode(mode);
    return "";
}
