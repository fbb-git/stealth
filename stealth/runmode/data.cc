#include "runmode.ih"

LinearMap<RunMode::Mode, char const *> const RunMode::s_modeName = 
    {
        {INTEGRITY_SCAN, "INTEGRITY_SCAN"},
        {RERUN,          "RERUN"},
        {SUSPEND,        "SUSPEND"},
        {RESUME,         "RESUME"},
        {RELOAD,         "RELOAD"},
        {TERMINATE,      "TERMINATE"},
    };








