#include "options.ih"

string Options::setLog()
{
    string logName;
    if (d_arg.option(&logName, 'l'))
    {
        d_log.open(logName);
        if (not d_log)
            fmsg << "could not open " << logName << endl;

        d_multiStreambuf.insert(d_log);
    }
    return logName;
}
