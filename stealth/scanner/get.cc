#include "scanner.h2"

// Command forms:
//      GET                   remote-file local-file
//      GET NOTEST            remote-file local-file

void Scanner::get(string const &cmd)
{
    if (d_debug)
        cerr << "Scanner::get(): " << cmd << endl;

    removeFirstWord("GET");                         // strip off `GET'

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    // at this point we have the remote-file and the local-file in the
    // command. d_firstword[1] contains the remote filename,
    //          d_firstword[2] contains the rest    


    string source = d_firstWord[1];                 // get the (remote) source
    removeFirstWord(source.c_str());
    string destination = d_firstWord[1];            // get the local dest.

    if (Util::isDirectory(destination))             // is the dest. a dir. ?
        destination += "/" + Util::fileName(source); 


    if (d_debug)
        cerr << "Scanner::get(): scp <client>:" << source << " " << 
                                                     destination << endl;

    if (!Arg::getInstance().option('n'))    // unless -n (no execute commands)
    {
        nextCommand(d_sshFork.out(),        // start the next command
            d_sorter["CAT"] + " " + source);

        read(d_sshFork.in(), destination); // read its output
    }

    if (d_debug)
        cerr << "Scanner::get(): " << cmd << " DONE" << endl;
}


