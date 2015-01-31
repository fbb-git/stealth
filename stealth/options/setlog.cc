#include "options.ih"

string Options::setLog()
{
    string logName;
    if (d_arg.option(&logName, 'L'))
    {
cerr << "Setting logname " << logName << '\n';
cerr << "policyfile at " << d_policyFile.get() << '\n';
cerr << "BASE = " << (*d_policyFile)["BASE"] << '\n';

        Util::absPath((*d_policyFile)["BASE"], logName);

cerr << "Logname = " << logName << '\n';

        d_log.open(logName);
        if (not d_log)
            fmsg << "could not open " << logName << endl;

        d_log.setTimestamp(d_timestamp);

        d_multiStreambuf.insert(d_log);
    }
    return logName;
}
