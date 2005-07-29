#include "scanner.h2"

                                        // receives the next command to execute
void Scanner::execute(string const &cmd)
{
    if (!d_firstWord.match(cmd))        // determine first word and the rest
        Util::exit(1, "Corrupt line in policy file: %s", cmd.c_str());
    
    if (!Arg::getInstance().option('q'))// echo the command, unless -q found
        cerr << *d_cmdIterator << endl;

    if (d_firstWord[1] == "LABEL")      // set a label 
    {
        d_label = d_firstWord[3];       // the text beyond the LABEL keyword
        Util::replace(d_label,          // change \\n into newlines
                        "\\n", "\n");   
    }
    else if (d_firstWord[1] == "LOCAL") // run a local command
        local(d_firstWord[3]);
    else if (d_firstWord[1] == "GET")   // get a file from the client
        get(cmd);
    else if (d_firstWord[1] == "PUT")   // put a file to the client
        put(cmd);
    else                                // or run a remote command
        remote(cmd);            
}

