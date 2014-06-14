#include "log.ih"

void Log::header()
{
    d_log.clear();

    d_startSize = d_log.seekp(0, ios::end).tellp();  

    d_beginMail = d_startSize;
}







