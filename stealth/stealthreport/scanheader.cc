#include "stealthreport.ih"

void StealthReport::scanHeader()
{
    d_startSize = d_stealthreport.seekp(0, ios::end).tellp();  

    *this << "STEALTH integrity scan at " << 
                    Options::instance().rfc2822() << endl;

    d_beginMail = d_stealthreport.tellp();
}







