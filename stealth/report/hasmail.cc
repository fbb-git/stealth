#include "report.ih"

bool Report::hasMail() 
{
    return seekp(0, ios::end).tellp() > d_beginMail;
}

