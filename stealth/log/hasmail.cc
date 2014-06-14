#include "log.ih"

bool Log::hasMail() 
{
    return d_log.seekp(0, ios::end).tellp() > d_beginMail;
}

