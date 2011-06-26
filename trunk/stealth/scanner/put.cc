#include "scanner.ih"

// Command forms:
//      PUT                   local-file remote-file 
//      PUT NOTEST            local-file remote-file 

void Scanner::put(string const &cmd)
{
    imsg << "Scanner::put(): " << cmd << endl;

    removeFirstWord("PUT");                         // strip off `PUT'

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    // at this point we have the remote-file and the local-file in the
    // command. d_firstword[1] contains the remote filename,
    //          d_firstword[3] contains the rest    


    string source = s_firstWord[1];                 // get the (remote) source
    if (!source.length())
        d_reporter.error() << "PUT command requires source and destination" <<
                                                                        endl;
            
    s_firstWord.match(s_firstWord[3]);              // strip off source

    string destination = s_firstWord[1];            // get the local dest.
    if (!destination.length())
        d_reporter.error() << "At `PUT " << source << 
                            " <destination>': destination missing" << endl;
            
    if (Stat(destination).isType(Stat::DIRECTORY))  // is the dest. a dir. ?
        destination += "/" + fileName(source);      // then append sourcename


    imsg << "Scanner::put(): scp <client>:" << source << " " << 
                                                     destination << endl;

    string command = putCommand(source, destination);

    if (Arg::instance().option('n'))     // no run if -n
        return;

    d_sshFork << command << endl;       // flush

    write(source);                      // write the file using dd

    d_sshFork << "/bin/echo \"" << d_sentinel << " $?\""  << endl;
    
    waitForSentinel(d_sshFork);

    imsg << "Scanner::put(): " << cmd << " DONE" << endl;
}








