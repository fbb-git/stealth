#include "runmode.ih"

LinearMap<RunMode::Mode, char const *> const RunMode::s_modeName = 
    {
        {LEAVE,          "LEAVE"},
        {INTEGRITY_SCAN, "INTEGRITY_SCAN"},
        {WAITING,        "WAITING"},
        {RERUN,          "RERUN"},
        {SUSPEND,        "SUSPEND"},
        {RESUME,         "RESUME"},
        {RELOAD,         "RELOAD"},
        {TERMINATE,      "TERMINATE"},
    };

LinearMap<RunMode::Mode, int> const RunMode::s_mode2signal =
{
    {RELOAD,     SIGPIPE},
    {RESUME,     SIGUSR2},
    {SUSPEND,   SIGUSR1},
    {TERMINATE,  SIGTERM},
};








