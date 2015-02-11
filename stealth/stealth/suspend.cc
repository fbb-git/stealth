#include "stealth.ih"

void Stealth::suspend()
{
    m2 << "received SUSPEND request" << endl;

    d_report->timestamp("is suspended", d_integrityScans->nScans());
}
