#include "integrityscanner.ih"

bool IntegrityScanner::doCHECKcommand(Process &child)
{
    removeLOG();                        // remove optional 'LOG ='

    string logfile = s_firstWord[1];    // CHECK keywords are followed by 
                                        // the name of a logfile

    s_firstWord.match(s_firstWord[3]);  // redefine s_firstWord: 1st word
                                        // removed 

    if (not isdigit(s_firstWord[1][0]))
        d_pathOffset = numeric_limits<size_t>::max();
    else
    {
        d_pathOffset = stoul(s_firstWord[1]);
        s_firstWord.match(s_firstWord[3]);
    }

    nextCommand(child, s_firstWord[0]); // otherwise run the command

    child << flush;
                                        // and return whether there are any
                                        // differences. 
    return sameOutput(logfile, child);
}





