#include "util.h2"

void Util::handleRerun(int signum)
{
    signal(SIGHUP, handleRerun);
}
