#include "scanner.ih"

void Scanner::killChildren()
{
    d_sshFork.stop();
    d_shFork.stop();
}
