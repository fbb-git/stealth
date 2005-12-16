#include "scanner.ih"

// Command forms:
//      GET                   remote-file local-file
//      GET NOTEST            remote-file local-file

void Scanner::get(string const &cmd)
{
    Util::debug() << "Scanner::get(): " << cmd << endl;

    removeFirstWord("GET");                         // strip off `GET'

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    // at this point we have the remote-file and the local-file in the
    // command. d_firstword[1] contains the remote filename,
    //          d_firstword[3] contains the rest    


    string source = d_firstWord[1];                 // get the (remote) source

    if (!source.length())
        d_reporter.exit() << "GET command requires source and destination" <<
                            endl;
            

    d_firstWord.match(d_firstWord[3]);              // strip off source
    string destination = d_firstWord[1];            // get the local dest.

    if (!destination.length())
        d_reporter.exit() << 
            "At `GET " << source << " <destination>': destination missing" <<
            endl;
            
    if (Util::isDirectory(destination))             // is the dest. a dir. ?
        destination += "/" + Util::fileName(source); 


    Util::debug() << "Scanner::get(): scp <client>:" << source << " " << 
                                                     destination << endl;

    if (Arg::getInstance().option('n'))     // no run if -n
        return;

    nextCommand(d_sshFork.out(),        // start the next command
        d_sorter["DD"] + " if=" + source);

    read(d_sshFork.in(), destination); // read its output, tests exit value

    Util::debug() << "Scanner::get(): " << cmd << " DONE" << endl;
}


