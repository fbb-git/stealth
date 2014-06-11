#include "integrityscanner.ih"

void IntegrityScanner::killChildren()
{
    d_sshFork.stop();
    d_shFork.stop();
}
