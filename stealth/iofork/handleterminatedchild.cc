#include "iofork.ih"

void IOFork::handleTerminatedChild(int signum)
{
    signal(SIGCHLD, handleTerminatedChild);
}
