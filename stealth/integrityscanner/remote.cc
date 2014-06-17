#include "integrityscanner.ih"

void IntegrityScanner::remote(string const &cmd)
{
    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
        doCHECKcommand(d_sshFork);
    else
        doPlainCommand(d_sshFork);
}
