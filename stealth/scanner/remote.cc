#include "scanner.h2"

void Scanner::remote(string const &cmd)
{
    if (d_debug)
        cerr << "REMOTE: Command Run At The Client\n";

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
        doCHECKcommand(d_sshFork);
    else
        doPlainCommand(d_sshFork);

    dout("Scanner::remote(): " << cmd << " DONE");
}
