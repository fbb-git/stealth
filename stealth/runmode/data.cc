#include "runmode.ih"

LinearMap<volatile RunMode::Mode, char const *> const RunMode::s_modeName = 
    {
        {INTEGRITY_SCAN, "INTEGRITY_SCAN"},
        {WAIT,           "WAIT"},
        {RERUN,          "RERUN"},
        {SUSPEND,        "SUSPEND"},
        {RESUME,         "RESUME"},
        {RELOAD,         "RELOAD"},
        {TERMINATE,      "TERMINATE"},
    };

LinearMap<volatile RunMode::Mode, int> const RunMode::s_mode2signal =
{
    {RERUN,      SIGHUP},
    {RELOAD,     SIGPIPE},
    {RESUME,     SIGUSR2},
    {SUSPEND,    SIGUSR1},
    {TERMINATE,  SIGTERM},
};








