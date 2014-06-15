#include "stealthlog.ih"

bool StealthLog::hasMail() 
{
    return d_stealthlog.seekp(0, ios::end).tellp() > d_beginMail;
}

