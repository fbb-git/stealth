#include "util.h2"

void Util::processControlOptions()
{
    Arg &arg = Arg::getInstance();

    string value;
                                    // options for other stealth processes
    if (arg.option(&value, "rerun"))
    {    
        unsigned pid = getPid(value);

        if (kill(pid, SIGHUP))
            exit(1, "Can't send SIGHUP to process `%u'", pid);

        ::exit(0);                              // done
    }

    if (arg.option(&value, "terminate"))
    {    
        unsigned pid = getPid(value);

        if (kill(pid, SIGTERM))
            exit(1, "Can't terminate process `%u'", pid);

        ::exit(0);                              // done
    }


    if (arg.option('v'))
        showVersion();                

    if
    (
        !arg.nArgs()                // provide usage if no arguments
        ||
        arg.option(0, "usage") 
        || 
        arg.option(0, "help")
    )
        usage();                    // were received


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
            exit(1, "--repeat requires --keep-interval");

        s_keepAlive = true;
        istringstream in(value);

        if (!(in >> s_repeatInterval))          // value 0: wait indefinite
            exit(1, "--repeat requires <seconds> until next run");

        if (s_repeatInterval < 60)
        {
            cerr << "`--repeat " << s_repeatInterval << 
                    "' changed to: `--repeat 60'\n";
            s_repeatInterval = 60;
        }
        else if (s_repeatInterval > INT_MAX)
            s_repeatInterval = INT_MAX;
    }

    randomDelay();                  // determine any random delay
}


