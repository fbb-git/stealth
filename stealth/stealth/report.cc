#include "stealth.ih"

void Stealth::report(char const *label)
{
    *d_reporter << 
        "STEALTH " << label << " after " << d_integrityScanner->nScans() << 
        " scans at " << DateTime() << endl;
}
