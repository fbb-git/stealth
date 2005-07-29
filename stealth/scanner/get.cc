#include "scanner.h2"

// Command forms:
//      GET                   remote-file local-file
//      GET NOTEST            remote-file local-file

void Scanner::get(string const &cmd)
{
    if (Util::debug())
        cerr << "Scanner::get(): " << cmd << endl;

    removeFirstWord("GET");                         // strip off `GET'

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    // at this point we have the remote-file and the local-file in the
    // command. d_firstword[1] contains the remote filename,
    //          d_firstword[3] contains the rest    


    string source = d_firstWord[1];                 // get the (remote) source

    if (!source.length())
        Util::exit(1, "GET command requires source and destination");
            

    d_firstWord.match(d_firstWord[3]);              // strip off source
    string destination = d_firstWord[1];            // get the local dest.

    if (!destination.length())
        Util::exit(1, "At `GET %s <destination>': destination missing", 
                                    source.c_str());
            
    if (Util::isDirectory(destination))             // is the dest. a dir. ?
        destination += "/" + Util::fileName(source); 


    if (Util::debug())
        cerr << "Scanner::get(): scp <client>:" << source << " " << 
                                                     destination << endl;

    if (Arg::getInstance().option('n'))     // no run if -n
        return;

    nextCommand(d_sshFork.out(),        // start the next command
        d_sorter["DD"] + " if=" + source);

    read(d_sshFork.in(), destination); // read its output, tests exit value

    if (Util::debug())
        cerr << "Scanner::get(): " << cmd << " DONE" << endl;
}


