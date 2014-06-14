#include "log.ih"

void Log::rewind()
{
    imsg << "Seeking to pos " << d_startSize << ": " << 
            d_log.seekg(d_startSize).tellg() << endl;
}

