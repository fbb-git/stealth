#include "scanner.ih"

                                        // receives the next command to execute
void Scanner::execute(string const &cmd)
{
    if (!(d_firstWord << cmd))          // determine first word and the rest
        d_reporter.exit() << "Corrupt line in policy file: " << cmd << endl;
    
    if (Arg::getInstance().option("de"))// echo the command with -d, -e
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

