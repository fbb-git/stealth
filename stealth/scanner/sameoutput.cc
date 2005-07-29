#include "scanner.h2"

bool Scanner::sameOutput(string const &logfile, istream &extractor)
{
    string current = logfile + ".cur";      // create current logfile

    if (!Util::mkdir(current))              // make sure directory exists
        Util::exit(1, "Unable to create the logfile `%s'", current.c_str());
 
    dout("Scanner::sameOutput(): logs to " << current);
   
    copy(extractor, current);               // copy the info in extractor
                                            // to the current logfile

    if (access(logfile.c_str(), R_OK))      // no old report yet
    {
        if (Util::debug())
            cerr << "writing new report: " << logfile << "\n";

        rename(current.c_str(), logfile.c_str());   // install `logfile'


        if (d_label.length())
        {
            dout("Scanner::sameOutput(): writing label: " << d_label);
            d_reporter << d_label << endl;
        }

        d_reporter << "Initialized report on " << logfile << endl;
        dout("Scanner::sameOutput(): Initialized  report on " << logfile);
        return true;
    }

    if (Util::debug())
        cerr << "comparing new integrity scan results to: `" << 
                                                        logfile << "'\n";

    return noDifferences(current, logfile); // return true if there aren't any
                                            // differences.
}




