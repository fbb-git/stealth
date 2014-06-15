#include "stealthlog.ih"

void StealthLog::rewind()
{
    imsg << "Seeking to pos " << d_startSize << ": " << 
            d_stealthlog.seekg(d_startSize).tellg() << endl;
}

