#include "monitor.ih"

void Monitor::handleRepeatOption()
{
    Arg &arg = Arg::instance();

    string value;

    if (arg.option(&value, "repeat"))
    {
        if (!s_keepAlive)
            msg() << "--repeat requires --keep-alive" << fatal;

        istringstream in(value);

        if (!(in >> s_repeatInterval))          // value 0: wait indefinite
            msg() << "--repeat requires <seconds> until next run" << fatal;

        if (s_repeatInterval < s_shortestRepeatInterval)
        {
            msg() << "`--repeat " << s_repeatInterval << 
                    "' changed to: `--repeat " << s_shortestRepeatInterval <<
                                                              '\'' << warning;
            s_repeatInterval = s_shortestRepeatInterval;
        }
        else if (s_repeatInterval > INT_MAX)
            s_repeatInterval = INT_MAX;
    }
}


