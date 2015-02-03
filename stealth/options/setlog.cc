#include "options.ih"

string Options::setLog()
{
    string logName;
    if (d_arg.option(&logName, 'L'))
    {
        Util::absPath((*d_policyFile)["BASE"], logName);

        d_log.open(logName);
        if (not d_log)
            fmsg << "could not open " << logName << endl;

        d_log.setTimestamp(d_timestamp);

        d_multiStreambuf->insert(d_log);
    }
    return logName;
}
