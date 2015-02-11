#include "stealthreport.ih"

void StealthReport::refresh()
{
    clear();

    d_startSize = seekp(0, ios::end).tellp();  

    d_beginMail = d_startSize;
}







