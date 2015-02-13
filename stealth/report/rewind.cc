#include "report.ih"

void Report::rewind()
{
    clear();
    seekg(d_startSize).tellg();
}

