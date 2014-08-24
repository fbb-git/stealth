#include "stealthlog.ih"

void StealthLog::scanHeader()
{
    d_startSize = d_stealthlog.seekp(0, ios::end).tellp();  

    *this << "STEALTH integrity scan at " << 
                    Options::instance().rfc2822() << endl;

    d_beginMail = d_stealthlog.tellp();
}







