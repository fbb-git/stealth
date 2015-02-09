#include "stealthreport.ih"

void StealthReport::rewind()
{
    d_stealthreport.clear();
    d_stealthreport.seekg(d_startSize).tellg();
}

