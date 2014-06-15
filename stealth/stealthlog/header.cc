#include "stealthlog.ih"

void StealthLog::header()
{
    d_stealthlog.clear();

    d_startSize = d_stealthlog.seekp(0, ios::end).tellp();  

    d_beginMail = d_startSize;
}







