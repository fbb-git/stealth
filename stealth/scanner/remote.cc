#include "scanner.ih"

void Scanner::remote(string const &cmd)
{
    msg() << "REMOTE: Command Run At The Client" << info;

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
        doCHECKcommand(d_sshFork);
    else
        doPlainCommand(d_sshFork);

    msg() << "Scanner::remote(): " << cmd << " DONE" << info;
}
