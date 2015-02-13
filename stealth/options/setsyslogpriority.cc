#include "options.ih"

void Options::setSyslogPriority()
{
    string option;
    if (not d_arg.option(&option, "syslog-priority"))
        d_syslogStruct.priority = s_defaultSyslogPriority;
    else
    {
        LinearMap<std::string, Priority>::const_iterator 
            iter = s_syslogPriorities.find(option);
    
        if (iter == s_syslogPriorities.end())
            fmsg << "syslog priority " << option << " not supported" << noidl;
    
        d_syslogStruct.priority = iter->second;
    }
}            

