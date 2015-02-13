#include "integrityscanner.ih"

bool IntegrityScanner::sameOutput(string const &logfile, Process &extractor)
{
    string current = logfile + ".cur";      // create current logfile

    if (!Util::mkdir(current))              // make sure directory exists
        fmsg << "unable to create the logfile `" << current << '\'' << 
                                                                        endl;
 
    m3 << "logs to " << current << endl;
   
    copy(extractor, current);               // copy the info in extractor
                                            // to the current logfile

    if (access(logfile.c_str(), R_OK) != 0) // no old report yet
    {
        m3 << "writing new report: " << logfile << '\n';

        rename(current.c_str(), logfile.c_str());   // install `logfile'

        if (d_label.length())
            d_stealthLog << d_label << endl;

        d_stealthLog << "Initialized report on " << logfile << endl;

        m3 << "initialized  report on " << logfile << endl;
        return true;
    }

    m3 << "comparing new integrity scan results to: `" << logfile << '\'' <<
                                                                        endl;

    return noDifferences(current, logfile); // return true if there aren't any
                                            // differences.
}





