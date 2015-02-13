#include "report.ih"

void Report::scanHeader()
{
    d_startSize = endpos();

    *this << "STEALTH integrity scan at " << d_options.rfc2822() << endl;

    d_beginMail = tellp();
}







