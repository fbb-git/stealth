#include "integrityscanner.ih"

// Command forms:
//      GET                   remote-file local-file
//      GET NOTEST            remote-file local-file

void IntegrityScanner::get(string const &cmd)
{
    removeFirstWord("GET");                         // strip off `GET'

    d_testExitValue = !removeFirstWord("NOTEST");   // [NOTEST] ...

    // at this point we have the remote-file and the local-file in the
    // command. d_firstword[1] contains the remote filename,
    //          d_firstword[3] contains the rest    

    string source = s_firstWord[1];                 // get the (remote) source

    if (!source.length())
        d_stealthLog << "GET command requires source and destination" <<
                                                        StealthEnums::leave;
            
    s_firstWord.match(s_firstWord[3]);              // strip off source
    string destination = s_firstWord[1];            // get the local dest.

    if (!destination.length())
        d_stealthLog << 
            "GET " << source << " <destination>': destination missing" <<
                                                        StealthEnums::leave;
            
    if (Stat(destination).isType(Stat::DIRECTORY))  // is the dest. a dir. ?
        destination += "/" + fileName(source); 

    nextCommand(d_sshFork,                  // start the next command
        d_policyFile["DD"] + " if=" + source);

    read(d_sshFork, destination);       // read its output, tests exit value
}
