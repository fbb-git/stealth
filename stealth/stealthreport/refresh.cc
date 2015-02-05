#include "stealthreport.ih"

void StealthReport::refresh()
{
    d_stealthreport.clear();

    d_startSize = d_stealthreport.seekp(0, ios::end).tellp();  

    d_beginMail = d_startSize;
}







