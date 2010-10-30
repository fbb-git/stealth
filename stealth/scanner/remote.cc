#include "scanner.ih"

void Scanner::remote(string const &cmd)
{
    imsg << "REMOTE: Command Run At The Client" << endl;

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
        doCHECKcommand(d_sshFork);
    else
        doPlainCommand(d_sshFork);

    imsg << "Scanner::remote(): " << cmd << " DONE" << endl;
}
