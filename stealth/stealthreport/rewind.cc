#include "stealthreport.ih"

void StealthReport::rewind()
{
    clear();
    seekg(d_startSize).tellg();
}

