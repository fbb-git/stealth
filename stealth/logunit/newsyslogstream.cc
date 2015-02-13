#include "logunit.ih"

ostream *LogUnit::newSyslogStream()
try
{
    SyslogStruct const &info = d_options.syslogStruct();

    return info.requested ? 
                new SyslogStream(info.tag, info.priority, info.facility)
            :
                0;
}
catch (exception const &exc)
{
    fmsg << "cannot write syslog messages" << endl;
    return 0;       // to make the compiler happy
}
