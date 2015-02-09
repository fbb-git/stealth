#include "logunit.ih"

void LogUnitBridge::initLog(ostream &fatal, 
                            string const &logName, TimeStamps timestamp)
{
    try
    {
        d_log.open(logName);
    }
    catch (exception const &exc)
    {
        fatal << exc.what() << leave;
    }

    d_log.setTimestamp(timestamp);

    d_multiStreambuf.insert(d_log);
}
