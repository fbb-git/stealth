#include "report.ih"

void Report::mail()
{
    if (hasMail())
        processMail();
    else
        m3 << "No new logs to mail" << endl;
}
