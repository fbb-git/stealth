#include "scanner.ih"

void Scanner::preamble()
{
    d_sshFork.start();          // start the ssh connection
    d_shFork.start();           // start the sh-connection to the localhost

                                // try to echo a sentinel by having
                                // the ssh connection echo it    
    Util::debug() << "Inserting " << d_sentinel << " into " << 
                    d_sorter["SSH"] << endl;

    d_sshFork << "/bin/echo \"" << d_sentinel << "\"" << endl;

    Util::debug() << "Waiting for " << d_sentinel << " from " << 
                                                d_sorter["SSH"] << endl;

    d_testExitValue = false;
    waitForSentinel(d_sshFork);  // continue after reading 

    Util::debug() << d_sorter["SSH"] << " appears to be functioning well\n";
}
