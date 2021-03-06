#include "options.ih"

Options *Options::s_options = 0;

char const Options::s_defaultSyslogIdent[]      = "STEALTH";
Facility Options::s_defaultSyslogFacility   = Facility::DAEMON;
Priority Options::s_defaultSyslogPriority   = Priority::NOTICE;

LinearMap<Options::Mode, char const *> const Options::s_modeName = 
    {
        {RELOAD,    "reload"},
        {RERUN,     "rerun"},
        {SUSPEND,   "suspend"},
        {RESUME,    "resume"},
        {TERMINATE, "terminate"}
    };

LinearMap<string, Facility> const Options::s_syslogFacilities = 
    {
        {"DAEMON", Facility::DAEMON}, 
        {"LOCAL0", Facility::LOCAL0},
        {"LOCAL1", Facility::LOCAL1},
        {"LOCAL2", Facility::LOCAL2},
        {"LOCAL3", Facility::LOCAL3},
        {"LOCAL4", Facility::LOCAL4},
        {"LOCAL5", Facility::LOCAL5},
        {"LOCAL6", Facility::LOCAL6},
        {"LOCAL7", Facility::LOCAL7},
        {"USER",   Facility::USER}
    };

LinearMap<string, Priority> const Options::s_syslogPriorities = 
    {
       {"EMERG",    Priority::EMERG},
       {"ALERT",    Priority::ALERT},
       {"CRIT",     Priority::CRIT},
       {"ERR",      Priority::ERR},
       {"WARNING",  Priority::WARNING},
       {"NOTICE",   Priority::NOTICE},
       {"INFO",     Priority::INFO},
       {"DEBUG",    Priority::DEBUG}
    };

size_t Options::s_defaultVerbosity = 1;
