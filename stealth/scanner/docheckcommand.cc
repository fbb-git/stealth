#include "scanner.ih"

bool Scanner::doCHECKcommand(Process &child)
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

    imsg << "running checked command: ";

    if (d_pathOffset != numeric_limits<size_t>::max())
        imsg << "(pathOffset = " << d_pathOffset << ") ";

    imsg << '`' << s_firstWord[0] << '\'' << endl;

    if (d_arg.option('n'))              // -n (no go) option?
        return true;                    // then indicate by implication that
                                        // the command was processed without
                                        // differing from the previous run

    nextCommand(child, s_firstWord[0]); // otherwise run the command

    child << flush;
                                        // and return whether there are any
                                        // differences. 
    return sameOutput(logfile, child);
}





