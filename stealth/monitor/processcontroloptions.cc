#include "monitor.ih"

void Monitor::processControlOptions()
{
    Arg &arg = Arg::instance();

    string value;
                                    // options for other stealth processes
    if (arg.option(&value, "rerun"))
        signalStealth(SIGHUP, "SIGHUP", value);     // exits

    if (arg.option(&value, "terminate"))
        signalStealth(SIGTERM, "SIGTERM", value);   // exits

    if (arg.option(&value, "suppress"))
        lock(value);                                // lock locally, let the
                                                    // integrity wait, exits
    if (arg.option(&value, "resume"))
        signalStealth(SIGUSR2, "SIGUSR2", value);   // exits

                                                // options for this process:
    s_keepAlive = arg.option(&value, "keep-alive");

    if (s_keepAlive)
    {
        s_repeatInterval = INT_MAX;
        Lock::setRunFilename(value);
    }

    if (arg.option(&value, "repeat"))
    {
        if (!s_keepAlive)
            msg() << "--repeat requires --keep-interval" << fatal;

        s_keepAlive = true;
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

    randomDelay();                  // determine any random delay
}


