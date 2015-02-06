#include "options.ih"

void Options::setVerbosity()
{
    string verbosity;

    d_verbosity = (d_arg.option(&verbosity, 'V')) ?
                                stoul(verbosity)
                            :
                                s_defaultVerbosity;

    Msg::setVerbosity(d_verbosity);
}



