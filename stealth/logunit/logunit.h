#ifndef INCLUDED_LOGUNIT_
#define INCLUDED_LOGUNIT_

// Messages sent to m1, m2, and m3 (see ../msg) are sent to imsg.
//
// imsg receives its info from this class's d_msg stream, through
// imsg.reset(d_msg) 
// 
// d_msg uses d_multiStreambuf as its streambuffer
//
// d_multiStreambuf is configured, if applicable, with d_syslog and d_log
//
// LogUnit itself has no public interface elements, except for the functions
// handling its singleton (re)construction. All information sent to the
// LogUnit's streams are received via imsg and m1..m3.
//

#include <iosfwd>
#include <bobcat/log>

#include "../syslogstruct/syslogstruct.h"

class LogUnitBridge;

class LogUnit
{
    static LogUnitBridge *s_logUnit;

    public:
        static void init(SyslogStruct const &syslogStruct,
                         std::string const &logName, FBB::TimeStamps stamp,
                         bool stdout);
};
        
#endif
