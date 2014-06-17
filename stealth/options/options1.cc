#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_msg(&d_multiStreambuf),
    d_maxSizeStr("10M")
{
    // --help and --version already handled by versionHelp, but if nothing
    // is requested on the command line help is also provided.
    if (
        d_arg.nArgs() == 0 && d_arg.nOptions() == 0 && 
        d_arg.nLongOptions() == 0
    )
    {
        usage(d_arg.basename());
        throw 0;
    }

    oldOptions();

    if ((d_reload = d_arg.option(0, "reload")))
        d_mode = RELOAD;

    if ((d_rerun = d_arg.option(0, "rerun")))
        d_mode = RERUN;

    if ((d_terminate = d_arg.option(0, "terminate")))
        d_mode = TERMINATE;

    if ((d_suspend = d_arg.option(0, "suspend")))
        d_mode = SUSPEND;

    if ((d_resume = d_arg.option(0, "resume")))
        d_mode = RESUME;

    if ((d_daemon = d_arg.option(&d_runFile, 'd')))
    {
        d_repeatInterval = numeric_limits<int>::max();
//        Lock::setRunFilename(d_runFile);
    }

    checkAction();

    if (d_mode & (RELOAD | RERUN | TERMINATE | SUSPEND | RESUME))
        d_runFile = d_arg[0];
    
    loadConfigFile();

    if (d_arg.option('o'))
    {
        if (d_daemon)
            wmsg << "--stdout ignored: conflicts with --daemon" << endl;
        else
            d_multiStreambuf.insert(cout);
    }

    string logName;
    if (d_arg.option(&logName, 'l'))
    {
        d_log.open(logName);
        if (not d_log)
            fmsg << "could not open " << logName << endl;

        d_multiStreambuf.insert(d_log);
    }

    setMail();
    setCommandNr();
    setSkipFilePath();

    bool useSyslog = setSyslog();

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

    setRepeat();
    setRandomDelay();

    d_policyFilePath = Util::realPath(d_arg[0]);
}       










