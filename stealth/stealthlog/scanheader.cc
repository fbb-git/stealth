#include "stealthlog.ih"

void StealthLog::scanHeader()
{
    d_startSize = d_stealthlog.seekp(0, ios::end).tellp();  

    *this << "STEALTH integrity scan at " << DateTime() << endl;

    d_beginMail = d_stealthlog.tellp();
}







