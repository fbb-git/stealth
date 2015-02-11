#ifndef INCLUDED_LOGUNIT_
#define INCLUDED_LOGUNIT_

#include <memory>
#include <ostream>

class Options;

namespace FBB
{
    class LogBuffer;
    class Syslogbuf;
    class MultiStreambuf;
}

#include "../options/options.h"

class LogUnit
{
    Options &d_options;

    std::unique_ptr<std::streambuf> d_logbuf;
    std::ostream d_log;

    std::unique_ptr<std::streambuf> d_syslogbuf;
    std::ostream d_syslog;

    std::unique_ptr<FBB::MultiStreambuf> d_imsgBuf;
    std::unique_ptr<FBB::MultiStreambuf> d_fmsgBuf;

    public:
        LogUnit(Options &options);

        void setupLogs();
};
        
#endif
