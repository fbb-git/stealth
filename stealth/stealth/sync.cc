#include "stealth.ih"

int LogReportbuf::sync()
{
    d_report.flush();
    d_report.mail();
    return 0;
}
