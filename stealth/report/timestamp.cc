#include "report.ih"

void Report::timestamp(char const *label, size_t nScans)
{
    static char plural[] = "s";

    plural[0] = nScans != 1 ? 's' : 0;

    *this << "STEALTH " << label << " after " << nScans << " scan" <<
                            plural << " at " << d_options.rfc2822() << endl;
    mail();
}
