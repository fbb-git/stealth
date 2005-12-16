#include "scanner.ih"

void Scanner::nextCommand(ostream &out, string const &command)
{
    Util::debug() << "Scanner::nextCommand(): inserting\n" << command << \
            "\nand: echo " << d_sentinel << " $?" << endl;

                        // run the command, then 
                        // echo the sentinel and returnvalue
    out << command << endl <<
           "/bin/echo \"" << d_sentinel << " $?\""  << endl;

    if (!out)
        d_reporter.exit() << 
            "Inserting command `" << d_firstWord[0] << "' failed." << endl;
}
