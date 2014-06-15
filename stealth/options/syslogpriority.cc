#include "options.ih"

Priority Options::syslogPriority() const
{
    Priority priority;

    string option;
    if (not d_arg.option(&option, "syslog-priority"))
        priority = s_defaultSyslogPriority;
    else
    {
        LinearMap<std::string, Priority>::const_iterator 
            iter = s_syslogPriorities.find(option);
    
        if (iter == s_syslogPriorities.end())
            fmsg << "syslog priority " << option << " not supported" << endl;
    
        priority = iter->second;
    }

    return priority;
}            

