#include "util.h2"

void Util::handleSIGUSR1(int signum)
{
    signal(SIGUSR1, handleRerun);
}
