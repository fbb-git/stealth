#include "scanner.h2"

void Scanner::preamble()
{
    d_sshFork.fork();          // start the ssh connection
    d_shFork.fork();           // start the sh-connection to the localhost

                                // try to echo a sentinel by having
                                // the ssh connection echo it    
    dout("Inserting " << d_sentinel << " into " << d_sorter["SSH"]);
    d_sshFork.out() << "/bin/echo \"" << d_sentinel << "\"" << endl;

    dout("Waiting for " << d_sentinel << " from " << d_sorter["SSH"]);

    d_testExitValue = false;
    waitForSentinel(d_sshFork.in());  // continue after reading 

    if (d_debug)
        cerr << d_sorter["SSH"] << " appears to be functioning well\n";
}
