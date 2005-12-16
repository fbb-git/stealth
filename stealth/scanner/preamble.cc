#include "scanner.ih"

void Scanner::preamble()
{
    d_sshFork.fork();          // start the ssh connection
    d_shFork.fork();           // start the sh-connection to the localhost

    s_sshPid = d_sshFork.getPid();
    s_shPid = d_shFork.getPid();

                                // try to echo a sentinel by having
                                // the ssh connection echo it    
    Util::debug() << "Inserting " << d_sentinel << " into " << 
                    d_sorter["SSH"] << endl;

    d_sshFork.out() << "/bin/echo \"" << d_sentinel << "\"" << endl;

    Util::debug() << "Waiting for " << d_sentinel << " from " << 
                                                d_sorter["SSH"] << endl;

    d_testExitValue = false;
    waitForSentinel(d_sshFork.in());  // continue after reading 

    Util::debug() << d_sorter["SSH"] << " appears to be functioning well\n";
}
