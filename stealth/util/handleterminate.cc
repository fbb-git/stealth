#include "util.h2"

void Util::handleTerminate(int signal)
{
    s_keepAlive = false;
}
