#include "ipc.ih"

LinearMap<int, char const *> const IPC::s_signame = 
    {
        {SIGPIPE,   "SIGPIPE"},
        {SIGHUP,    "SIGHUP"},
        {SIGTERM,   "SIGTERM"},
        {SIGUSR1,   "SIGUSR1"},
        {SIGUSR2,   "SIGUSR2"},
    };
