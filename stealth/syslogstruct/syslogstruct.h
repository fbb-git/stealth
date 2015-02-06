#ifndef INCLUDED_SYSLOGSTRUCT_
#define INCLUDED_SYSLOGSTRUCT_

#include <string>
#include <bobcat/syslogstream>

struct SyslogStruct
{
    bool requested;
    FBB::Priority priority; 
    FBB::Facility facility;
    std::string tag;

    SyslogStruct();
};
        
inline SyslogStruct::SyslogStruct()
:
    requested(false)
{}

#endif
