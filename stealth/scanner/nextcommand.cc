#include "scanner.h2"

void Scanner::nextCommand(ostream &out, string const &command)
{
    dout("Scanner::nextCommand(): inserting\n" << command << \
            "\nand: echo " << d_sentinel << " $?");

                        // run the command, then 
                        // echo the sentinel and returnvalue
    out << command << endl <<
           "/bin/echo \"" << d_sentinel << " $?\""  << endl;

    if (!out)
        Util::exit(1, 
            "Inserting command `%s' failed.", d_firstWord[0].c_str());
}
