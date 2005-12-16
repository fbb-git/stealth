#include "scanner.ih"

bool Scanner::sameOutput(string const &logfile, istream &extractor)
{
    string current = logfile + ".cur";      // create current logfile

    if (!Util::mkdir(current))              // make sure directory exists
        d_reporter.exit() << "Unable to create the logfile `" <<
                                                    current << "'" << endl;
 
    Util::debug() << "Scanner::sameOutput(): logs to " << current << endl;
   
    copy(extractor, current);               // copy the info in extractor
                                            // to the current logfile

    if (access(logfile.c_str(), R_OK))      // no old report yet
    {
        Util::debug() << "writing new report: " << logfile << endl;

        rename(current.c_str(), logfile.c_str());   // install `logfile'

        if (d_label.length())
        {
            Util::debug() << "Scanner::sameOutput(): writing label: " << 
                                                            d_label << endl;
            d_reporter << d_label << endl;
        }

        d_reporter << "Initialized report on " << logfile << endl;
        Util::debug() << "Scanner::sameOutput(): Initialized  report on " <<
                                                            logfile << endl;
        return true;
    }

    Util::debug() << "comparing new integrity scan results to: `" << 
                                                    logfile << "'" << endl;

    return noDifferences(current, logfile); // return true if there aren't any
                                            // differences.
}




