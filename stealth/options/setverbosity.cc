#include "options.ih"

void Options::setVerbosity(bool useSyslog, string const &logName)
{
    string verbosity;
    bool verb;
    size_t verbosityValue = (verb = d_arg.option(&verbosity, 'V')) ?
                                stoul(verbosity)
                            :
                                s_defaultVerbosity;

    if (useSyslog || logName.length() != 0)
        imsg.reset(d_msg);

    Msg::setVerbosity(verbosityValue);
}



