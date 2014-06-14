#include "log.ih"

void Log::scanHeader()
{
    d_startSize = d_log.seekp(0, ios::end).tellp();  

    *this << "STEALTH integrity scan at " << DateTime() << endl;

    d_beginMail = d_log.tellp();
}







