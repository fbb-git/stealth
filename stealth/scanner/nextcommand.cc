#include "scanner.ih"

void Scanner::nextCommand(ostream &out, string const &command)
{
    Util::debug() << "Scanner::nextCommand(): inserting\n" << command << \
            "\nand: echo " << d_sentinel << " $?\n";

                        // run the command, then 
                        // echo the sentinel and returnvalue
    out << command << "\n" <<
           "/bin/echo \"" << d_sentinel << " $?\""  << "\n";

    if (!out)
        d_reporter.exit() << 
            "Inserting command `" << s_firstWord[0] << "' failed." << endl;
}
