#include "options.ih"

bool Options::setSyslog()
{
    if (not d_arg.option(0, "syslog"))
        return false;

    if (d_ipc)
        fmsg << "--syslog* options incompatible with IPC calls" << endl;

    d_syslog = make_shared<SyslogStream>(syslogTag(), syslogPriority(),
                            syslogFacility());

    d_multiStreambuf.insert(*d_syslog);
    return true;
}
