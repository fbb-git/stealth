#include "stealthreport.ih"

void StealthReport::scanHeader()
{
    d_startSize = seekp(0, ios::end).tellp();  

    *this << "STEALTH integrity scan at " << d_options.rfc2822() << endl;

    d_beginMail = tellp();
}







