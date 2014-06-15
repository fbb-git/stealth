#include "integrityscanner.ih"

void IntegrityScanner::remote(string const &cmd)
{
    m1 << "REMOTE: Command Run At The Client" << endl;

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
        doCHECKcommand(d_sshFork);
    else
        doPlainCommand(d_sshFork);
}
