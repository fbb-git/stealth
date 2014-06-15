#include "stealthlog.ih"

void StealthLog::rewind()
{
    d_stealthlog.seekg(d_startSize).tellg();
}

