#include "logunit.ih"

void LogUnit::init(ostream &fatal, SyslogStruct const &syslogStruct,
                   string const &logName, TimeStamps timestamp,
                   bool stdout)
{
    if (s_logUnit != 0)
    {
        imsg.off();             // no more logging
        delete s_logUnit;       // and delete the current logUnit
    }

                                // define a new LogUnit(Bridge)
                                //
    s_logUnit = new LogUnitBridge(fatal, syslogStruct, logName, timestamp,
                                  stdout); 
}
