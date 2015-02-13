#include "options.ih"

void Options::setSyslog()
{
    d_syslogStruct.requested  = d_arg.option(0, "syslog");

    if (not d_syslogStruct.requested)
        return;

    if (d_ipc)
        fmsg << "--syslog* options incompatible with IPC calls" << noidl;


    if (not d_arg.option(&d_syslogStruct.tag, "syslog-tag"))
        d_syslogStruct.tag = s_defaultSyslogIdent;

    setSyslogPriority();
    setSyslogFacility();
}
