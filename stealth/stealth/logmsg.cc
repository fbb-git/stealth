#include "stealth.ih"

void Stealth::logMsg(char const *label)
{
    d_stealthLog << "STEALTH " << label << " after " << 
            d_integrityScanner->nScans() << " scans at " << DateTime() << 
            endl;
}
