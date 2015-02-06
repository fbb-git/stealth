#include "options.ih"

void Options::setSyslogFacility()
{
    string option;
    if (not d_arg.option(&option, "syslog-facility"))
        d_syslogStruct.facility = s_defaultSyslogFacility;
    else
    {
        LinearMap<string, Facility>::const_iterator 
            iter = s_syslogFacilities.find(option);
    
        if (iter == s_syslogFacilities.end())
            fmsg << "syslog facility " << option << " not supported" << endl;
    
        d_syslogStruct.facility = iter->second;
    }
}            

