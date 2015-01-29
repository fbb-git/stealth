#include "runmode.ih"

LinearMap<volatile RunMode::Mode, char const *> const RunMode::s_modeName = 
    {
        {INTEGRITY_SCAN, "INTEGRITY_SCAN"},
        {RERUN,          "RERUN"},
        {SUSPEND,        "SUSPEND"},
        {RESUME,         "RESUME"},
        {RELOAD,         "RELOAD"},
        {TERMINATE,      "TERMINATE"},
    };








