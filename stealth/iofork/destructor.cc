#include "iofork.ih"

IOFork::~IOFork()
{
    int pid = getPid();

    if (pid > 0)
    {
        dout("IOFork::~IOFork(): terminating childprocess " << pid);
        kill(pid, SIGTERM);
        kill(pid, SIGQUIT);
    }
}
