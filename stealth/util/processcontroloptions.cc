#include "util.ih"

void Util::processControlOptions()
{
    Arg &arg = Arg::getInstance();

    string value;
                                    // options for other stealth processes
    if (arg.option(&value, "rerun"))
        signalStealth(SIGHUP, "SIGHUP", value);     // exits

    if (arg.option(&value, "terminate"))
        signalStealth(SIGTERM, "SIGTERM", value);   // exits

    if (arg.option(&value, "suppress"))
        lock(value);                          // lock locally, let the
                                                    // integrity wait, exits
    if (arg.option(&value, "resume"))
        signalStealth(SIGUSR2, "SIGUSR2", value);   // exits

    if (arg.option('v'))                    
        showVersion();                              // exits

    if
    (
        !arg.nArgs()                // provide usage if no arguments
        ||                          // were received
        arg.option(0, "usage") 
        || 
        arg.option(0, "help")
    )
        usage();                                    // exits


                                                // options for this process:
    s_keepAlive = arg.option(&value, "keep-alive");
    if (s_keepAlive)
    {
        s_repeatInterval = INT_MAX;
        s_runFilename = value;
    }

    if (arg.option(&value, "repeat"))
    {
        if (!s_keepAlive)
            exit("--repeat requires --keep-interval");

        s_keepAlive = true;
        istringstream in(value);

        if (!(in >> s_repeatInterval))          // value 0: wait indefinite
            exit("--repeat requires <seconds> until next run");

        if (s_repeatInterval < s_shortestRepeatInterval)
        {
            cerr << "`--repeat " << s_repeatInterval << 
                    "' changed to: `--repeat " << s_shortestRepeatInterval <<
                                                                        "'\n";
            s_repeatInterval = s_shortestRepeatInterval;
        }
        else if (s_repeatInterval > INT_MAX)
            s_repeatInterval = INT_MAX;
    }
    randomDelay();                  // determine any random delay
}


