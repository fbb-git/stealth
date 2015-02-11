#include "stealthreport.ih"

void StealthReport::timestamp(char const *label, size_t nScans)
{
    *this << "STEALTH " << label << " after " << nScans << " scans at " << 
        Options::instance().rfc2822() << endl;

    mail();
    
}
