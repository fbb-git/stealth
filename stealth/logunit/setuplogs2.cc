#include "logunit.ih"

void LogUnit::setupLogs(ostream &stealthReport)
{
    setupLogs();
    d_fmsgbuf->insert(stealthReport);    
}
