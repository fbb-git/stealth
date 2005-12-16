#include "iofork.ih"

IOFork::~IOFork()
{
    int pid = getPid();

    if (pid > 0)
    {
        Util::debug() << "IOFork::~IOFork(): terminating childprocess " << 
                                                                pid << endl;
        kill(pid, SIGTERM);
        kill(pid, SIGQUIT);
    }
}
