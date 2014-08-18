#include "ipc.ih"

LinearMap<std::string, StealthEnums::Mode> const IPC::s_request = 
    {
        {"suspend",     SUSPEND},
        {"resume",      RESUME},
        {"rerun",       RERUN},
        {"reload",      RELOAD},
        {"terminate",   TERMINATE},
    };
