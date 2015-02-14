#include "logunit.ih"

void LogUnit::setupLogs(ostream &report)
{
    setupLogs();
    d_fmsgbuf->insert(report);    
}
