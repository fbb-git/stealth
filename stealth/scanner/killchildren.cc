#include "scanner.h2"

void Scanner::killChildren()
{
    kill(s_shPid, SIGTERM) && kill(s_shPid, SIGKILL);
    kill(s_sshPid, SIGTERM) && kill(s_sshPid, SIGKILL);
}
