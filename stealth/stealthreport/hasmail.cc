#include "stealthreport.ih"

bool StealthReport::hasMail() 
{
    return seekp(0, ios::end).tellp() > d_beginMail;
}

