#include "options.ih"

void Options::setVerbosity(bool useSyslog, string const &logName)
{
    string verbosity;
    bool verb;
    d_verbosity = (verb = d_arg.option(&verbosity, 'V')) ?
                                stoul(verbosity)
                            :
                                s_defaultVerbosity;

    if (useSyslog || logName.length() != 0)
        imsg.reset(d_msg);

    Msg::setVerbosity(d_verbosity);
}



