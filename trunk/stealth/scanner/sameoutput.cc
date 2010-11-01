#include "scanner.ih"

bool Scanner::sameOutput(string const &logfile, istream &extractor)
{
    string current = logfile + ".cur";      // create current logfile

    if (!Util::mkdir(current))              // make sure directory exists
        d_reporter.error() << "Unable to create the logfile `" <<
                                                    current << "'" << endl;
 
    imsg << "Scanner::sameOutput(): logs to " << current << endl;
   
    copy(extractor, current);               // copy the info in extractor
                                            // to the current logfile

    if (access(logfile.c_str(), R_OK))      // no old report yet
    {
        imsg << "writing new report: " << logfile << '\n';

        rename(current.c_str(), logfile.c_str());   // install `logfile'

        if (d_label.length())
        {
            imsg << "Scanner::sameOutput(): writing label: " << d_label << 
                                                                        '\n';
            d_reporter << d_label << endl;
        }

        d_reporter << "Initialized report on " << logfile << endl;
        imsg << "Scanner::sameOutput(): Initialized  report on " << logfile <<
                                                                        endl;
        return true;
    }

    imsg << "comparing new integrity scan results to: `" << logfile << '\'' <<
                                                                        endl;

    return noDifferences(current, logfile); // return true if there aren't any
                                            // differences.
}




