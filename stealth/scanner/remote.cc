#include "scanner.ih"

void Scanner::remote(string const &cmd)
{
    Util::debug() << "REMOTE: Command Run At The Client" << endl;

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
        doCHECKcommand(d_sshFork);
    else
        doPlainCommand(d_sshFork);

    Util::debug() << "Scanner::remote(): " << cmd << " DONE" << endl;
}
