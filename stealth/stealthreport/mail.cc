#include "stealthreport.ih"

void StealthReport::mail()
{
    if (hasMail())
        processMail();
    else
        m3 << "No new logs to mail" << endl;
}
