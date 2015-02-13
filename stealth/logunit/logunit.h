#ifndef INCLUDED_LOGUNIT_
#define INCLUDED_LOGUNIT_

#include <memory>
#include <ostream>

#include <bobcat/multistreambuf>

class Options;

namespace FBB
{
    class LogBuffer;
    class Syslogbuf;
}

class LogUnit
{
    Options &d_options;

    std::unique_ptr<std::ostream> d_log;
    std::unique_ptr<std::ostream> d_syslog;

    std::unique_ptr<FBB::MultiStreambuf> d_imsgbuf;
    std::unique_ptr<FBB::MultiStreambuf> d_fmsgbuf;

    public:
        LogUnit(Options &options);

        void setupLogs();
        void setupLogs(std::ostream &report);

        std::ostream *newSyslogStream();
        std::ostream *newLog();
};
        
#endif




