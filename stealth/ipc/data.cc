#include "ipc.ih"

LinearMap<char const *, StealthEnums::Mode> const IPC::s_request = 
    {
        {"Suspend",     SUSPEND},
        {"Resume",      RESUME},
        {"ReRun",       RERUN},
        {"Reload",      RELOAD},
        {"Terminate",   TERMINATE},
    };
