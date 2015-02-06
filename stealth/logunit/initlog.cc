#include "logunit.ih"

void LogUnitBridge::initLog(string const &logName, TimeStamps timestamp)
{
    d_log.open(logName);
    if (not d_log)
        fmsg << "could not open " << logName << endl;

    d_log.setTimestamp(timestamp);

    d_multiStreambuf.insert(d_log);
}
