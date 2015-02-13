#include "report.ih"

void Report::timestamp(char const *label, size_t nScans)
{
    *this << "STEALTH " << label << " after " << nScans << " scans at " << 
        d_options.rfc2822() << endl;

    mail();
}
