#include "util.h2"

void Util::processControlOptions()
{
    Arg &arg = Arg::getInstance();
    string value;
                                                // options for this process:
    s_keepAlive = arg.option(0, "keep-alive");

    if (s_keepAlive)
        s_repeatInterval = INT_MAX;

    if (arg.option(&value, "repeat"))
    {
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

                                    // options for other stealth processes
    if (arg.option(&value, "rerun"))
    {    
        unsigned pid;
        istringstream in(value);

        if (!(in >> pid) || !pid)
            exit(1, "--rerun requires stealth pid to rerun");

        if (kill(pid, SIGHUP))
            exit(1, "Can't send SIGHUP to process `%u'", pid);

        ::exit(0);                              // done
    }

    if (arg.option(&value, "terminate"))
    {    
        unsigned pid;
        istringstream in(value);

        if (!(in >> pid) || !pid)
            exit(1, "--terminate requires stealth pid to terminate");

        if (kill(pid, SIGTERM) && kill(pid, SIGKILL))
            exit(1, "Can't terminate process `%u'", pid);

        ::exit(0);                              // done
    }
}


