#include "stealth.ih"

void Stealth::logMsg(char const *label)
{
    d_stealthReport << "STEALTH " << label << " after " << 
            d_integrityScanner->nScans() << " scans at " << 
                                                d_options.rfc2822() << endl;
}
