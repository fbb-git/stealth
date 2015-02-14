#include "stealth.ih"

Stealth::~Stealth()
{
    if (d_options.daemon())
        unlink(d_options.unixDomainSocket().c_str());

    delete d_logReportbuf;
}




