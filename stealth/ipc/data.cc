#include "ipc.ih"

LinearMap<std::string, StealthEnums::Mode> const IPC::s_request = 
    {
        {"Suspend",     SUSPEND},
        {"Resume",      RESUME},
        {"ReRun",       RERUN},
        {"Reload",      RELOAD},
        {"Terminate",   TERMINATE},
    };
