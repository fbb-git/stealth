#include "runmode.ih"

LinearMap<RunMode::Mode, char const *> const RunMode::s_modeName = 
    {
        {ONCE,           "ONCE"},
        {KEEP_ALIVE,     "KEEP_ALIVE"},
        {RERUN,          "RERUN"},

        {RELOAD,         "RELOAD"},

        {SUPPRESS,       "SUPPRESS"},
        {SUPPRESSED,     "SUPPRESSED"},

        {RESUME,         "RESUME"},

        {TERMINATE,      "TERMINATE"},
        {TERMINATED,     "TERMINATED"},
    };

LinearMap<RunMode::Mode, int> const RunMode::s_mode2signal =
{
    {RELOAD,     SIGPIPE},
    {RESUME,     SIGUSR2},
    {SUPPRESS,   SIGUSR1},
    {TERMINATE,  SIGTERM},
};








