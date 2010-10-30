#include "scanner.ih"

void Scanner::nextCommand(ostream &out, string const &command)
{
    imsg << "Scanner::nextCommand(): inserting\n" << command << "\n"
                "and: echo " << d_sentinel << " $?" << endl;

                        // run the command, then 
                        // echo the sentinel and returnvalue
    out << command << "\n" <<
           "/bin/echo \"" << d_sentinel << " $?\""  << "\n";

    if (!out)
        d_reporter.error() << 
            "Inserting command `" << s_firstWord[0] << "' failed." << endl;
}
