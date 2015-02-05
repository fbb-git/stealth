#include "stealthreport.ih"

bool StealthReport::hasMail() 
{
    return d_stealthreport.seekp(0, ios::end).tellp() > d_beginMail;
}

