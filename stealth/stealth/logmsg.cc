#include "stealth.ih"

void Stealth::logMsg(char const *label)
{
    d_log << "STEALTH " << label << " after " << 
            d_integrityScanner->nScans() << " scans at " << DateTime() << 
            endl;
}
