#include "stealth.ih"

void Stealth::setupFatalReport()
{
    delete d_logReportbuf;

    d_logReportbuf = new LogReportbuf(*d_report);
    d_logReport.rdbuf(d_logReportbuf);
    d_logReport.clear();
}
