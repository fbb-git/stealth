#include "integrityscanner.ih"

void IntegrityScanner::nextCommand(ostream &out, string const &command)
{
    imsg << "IntegrityScanner::nextCommand(): inserting\n" << command << "\n"
                "and: echo " << d_sentinel << " $?" << endl;

                        // run the command, then 
                        // echo the sentinel and returnvalue
    out << command << "\n" 
           "/bin/echo \"" << d_sentinel << " $?\""  << endl;

    if (!out)
        d_reporter.error() << 
            "Inserting command `" << s_firstWord[0] << "' failed." << endl;
}