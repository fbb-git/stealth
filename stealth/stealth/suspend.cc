#include "stealth.ih"

void Stealth::suspend()
{
    m2 << "received SUSPEND request" << endl;

    timestamp("is suspended");
}
