#include "scanner.h2"

bool Scanner::doCHECKcommand(IOFork &child)
{
    removeLOG();                        // remove optional 'LOG ='

    string logfile = d_firstWord[1];    // CHECK keywords are followed by 
                                        // the name of a logfile

    d_firstWord.match(d_firstWord[3]);  // redefine d_firstWord: 1st word
                                        // removed 

    if (d_debug)
        cerr << "running checked command: `" << d_firstWord[0] << "'\n";

    if (Arg::getInstance().option('n')) // -n (no go) option?
        return true;                    // then indicate by implication that
                                        // the command was processed without
                                        // differing from the previous run

    nextCommand(child.out(),            // otherwise run the command
                    d_firstWord[0]);

                                        // and return whether there are any
                                        // differences. 
    return sameOutput(logfile, child.in());
}

