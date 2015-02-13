#include "report.ih"

void Report::refresh()
{
    clear();

    d_startSize = seekp(0, ios::end).tellp();  

    d_beginMail = d_startSize;
}







