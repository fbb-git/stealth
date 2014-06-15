#include "integrityscanner.ih"

void IntegrityScanner::startCommandShells() // preamble()
{
    d_sshFork.start();          // start the ssh connection
    d_shFork.start();           // start the sh-connection to the localhost

                                // try to echo a sentinel by having
                                // the ssh connection echo it    
    m3 << "Inserting " << d_sentinel << " into " << d_policyFile["SSH"] << 
                                                                        endl;

    d_sshFork << "/bin/echo \"" << d_sentinel << "\"" << endl;   // must flush

    m3 << "Waiting for " << d_sentinel << " from " << d_policyFile["SSH"] << 
                                                                        endl;

    d_testExitValue = false;
    waitForSentinel(d_sshFork);  // continue after reading 

    m3 << d_policyFile["SSH"] << " appears to be functioning well" << endl;
}
