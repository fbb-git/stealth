#include "scanner.h2"

void Scanner::killChildren()
{
    if (s_shPid)
        kill(s_shPid, SIGTERM) && kill(s_shPid, SIGKILL);
    if (s_sshPid)
        kill(s_sshPid, SIGTERM) && kill(s_sshPid, SIGKILL);
}
