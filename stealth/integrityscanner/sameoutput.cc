#include "integrityscanner.ih"

bool IntegrityScanner::sameOutput(string const &logfile, Process &extractor)
{
    string current = logfile + ".cur";      // create current logfile

    if (!Util::mkdir(current))              // make sure directory exists
        d_stealthLog << "Unable to create the logfile `" << current << "'" << 
                                                            StealthEnums::leave;
 
    imsg << "IntegrityScanner::sameOutput(): logs to " << current << endl;
   
    copy(extractor, current);               // copy the info in extractor
                                            // to the current logfile

    if (access(logfile.c_str(), R_OK))      // no old report yet
    {
        imsg << "writing new report: " << logfile << '\n';

        rename(current.c_str(), logfile.c_str());   // install `logfile'

        if (d_label.length())
        {
            imsg << "IntegrityScanner::sameOutput(): writing label: " << 
                    d_label << '\n';
            d_stealthLog << d_label << endl;
        }

        d_stealthLog << "Initialized report on " << logfile << endl;

        imsg << "IntegrityScanner::sameOutput(): Initialized  report on " << 
                logfile << endl;
        return true;
    }

    imsg << "comparing new integrity scan results to: `" << logfile << '\'' <<
                                                                        endl;

    return noDifferences(current, logfile); // return true if there aren't any
                                            // differences.
}





