#include "options.ih"

void Options::setVerbosity(bool useSyslog)
{
    string verbosity;
    bool verb;
    size_t verbosityValue = (verb = d_arg.option(&verbosity, 'V')) ?
                                stoul(verbosity)
                            :
                                s_defaultVerbosity;

    if (verb and ipc())
    {
        warnOption("--verbosity not used");
        verbosityValue = 0;
    }
    else if (useSyslog || logName.length() != 0)
        imsg.reset(d_msg);
    else
    {
        if (verb && verbosityValue != 0)
            wmsg << "--verbosity ignored: --syslog or --log not specified" << 
                                                                        endl;
        verbosityValue = 0;
    }

    Msg::setVerbosity(verbosityValue);
}
