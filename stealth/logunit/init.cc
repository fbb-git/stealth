#include "logunit.ih"

void LogUnit::init(SyslogStruct const &syslogStruct,
                   std::string const &logName, FBB::TimeStamps timestamp,
                   bool stdout)
{
    if (s_logUnit != 0)
    {
        imsg.off();             // no more logging
        delete s_logUnit;       // and delete the current logUnit
    }

                                // define a new LogUnit(Bridge)
                                //
    s_logUnit = new LogUnitBridge(syslogStruct, logName, timestamp, stdout);
}
