#include "options.ih"

Facility Options::syslogFacility() const
{
    Facility facility;

    string option;
    if (not d_arg.option(&option, "syslog-facility"))
        facility = s_defaultSyslogFacility;
    else
    {
        LinearMap<string, Facility>::const_iterator 
            iter = s_syslogFacilities.find(option);
    
        if (iter == s_syslogFacilities.end())
            fmsg << "syslog facility " << option << " not supported" << endl;
    
        facility = iter->second;
    }

    return facility;
}            

