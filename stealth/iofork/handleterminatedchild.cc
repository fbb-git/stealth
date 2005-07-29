#include "iofork.ih"

void IOFork::handleTerminatedChild(int)
{
    signal(SIGCHLD, handleTerminatedChild);
}
