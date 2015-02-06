#include "logunit.ih"

LogUnitBridge::LogUnitBridge(SyslogStruct const &syslogStruct,
                             string const &logName, TimeStamps timestamp,
                             bool stdout)
:
    d_syslogStream(syslogStruct.tag, 
                   syslogStruct.priority, syslogStruct.facility),
    d_msg(&d_multiStreambuf)
{
    bool useImsg = false;

    if (stdout)
    {
        useImsg = true;
        d_multiStreambuf.insert(cout);
    }

    if (syslogStruct.requested)
    {
        useImsg = true;
        d_multiStreambuf.insert(d_syslogStream);
    }

    if (not logName.empty())
    {
        initLog(logName, timestamp);
        useImsg = true;
    }

    if (useImsg)
    {
        imsg.on();
        imsg.reset(d_msg);
    }
}
