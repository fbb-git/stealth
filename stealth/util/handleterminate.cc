#include "util.h2"

void Util::handleTerminate(int sig)
{
    s_keepAlive = false;
}
