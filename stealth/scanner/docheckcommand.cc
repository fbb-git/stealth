#include "scanner.ih"

bool Scanner::doCHECKcommand(Process &child)
{
    removeLOG();                        // remove optional 'LOG ='

    string logfile = s_firstWord[1];    // CHECK keywords are followed by 
                                        // the name of a logfile

    s_firstWord.match(s_firstWord[3]);  // redefine s_firstWord: 1st word
                                        // removed 

    Util::debug() << "running checked command: `" << s_firstWord[0] << "'"
                                                                    << endl;

    if (Arg::instance().option('n')) // -n (no go) option?
        return true;                    // then indicate by implication that
                                        // the command was processed without
                                        // differing from the previous run

    nextCommand(child,                  // otherwise run the command
                    s_firstWord[0]);


                                        // and return whether there are any
                                        // differences. 
    return sameOutput(logfile, child);
}




