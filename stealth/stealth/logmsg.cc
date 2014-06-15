#include "stealth.ih"

void Stealth::logMsg(char const *label)
{
    d_stealthlog << "STEALTH " << label << " after " << 
            d_integrityScanner->nScans() << " scans at " << DateTime() << 
            endl;
}
