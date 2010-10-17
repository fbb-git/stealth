#include "scanner.ih"

bool Scanner::sameOutput(string const &logfile, istream &extractor)
{
    string current = logfile + ".cur";      // create current logfile

    if (!Util::mkdir(current))              // make sure directory exists
        d_reporter.error() << "Unable to create the logfile `" <<
                                                    current << "'" << endl;
 
    msg() << "Scanner::sameOutput(): logs to " << current << info;
   
    copy(extractor, current);               // copy the info in extractor
                                            // to the current logfile

    if (access(logfile.c_str(), R_OK))      // no old report yet
    {
        msg() << "writing new report: " << logfile << "\n";

        rename(current.c_str(), logfile.c_str());   // install `logfile'

        if (d_label.length())
        {
            msg() << "Scanner::sameOutput(): writing label: " << 
                                                            d_label << "\n";
            d_reporter << d_label << endl;
        }

        d_reporter << "Initialized report on " << logfile << endl;
        msg() << "Scanner::sameOutput(): Initialized  report on " <<
                                                            logfile << "\n";
        return true;
    }

    msg() << "comparing new integrity scan results to: `" << 
                                                    logfile << "'\n";

    return noDifferences(current, logfile); // return true if there aren't any
                                            // differences.
}




