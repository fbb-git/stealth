#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_msg(&d_multiStreambuf)
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

    if ((d_reload = d_arg.option(0, "reload")))
        d_mode = RELOAD;

    if ((d_rerun = d_arg.option(0, "rerun")))
        d_mode = RERUN;

    if ((d_terminate = d_arg.option(0, "terminate")))
        d_mode = TERMINATE;

    if ((d_suppress = d_arg.option(0, "suppress")))
        d_mode = SUSPEND;

    if ((d_resume = d_arg.option(0, "resume")))
        d_mode = RESUME;

    if ((d_keepAlive = d_arg.option(&d_runFile, "keep-alive")))
    {
        d_repeatInterval = numeric_limits<int>::max();
        Lock::setRunFilename(d_runFile);
    }

//    d_runFile = d_arg[0]; ??

    checkAction();

    loadConfigFile();


    if (d_arg.option('S'))
    {
        if (d_keepAlive)
            wmsg << "--stdout ignored: conflicts with --keep-alive" << endl;
        else
            d_multiStreambuf.insert(cout);
    }

    string logName;
    if (d_arg.option(&logName, 'L'))
    {
        d_log.open(logName);
        if (not d_log)
            fmsg << "could not open " << logName << endl;

        d_multiStreambuf.insert(d_log);
    }

    string mailType;
    if (d_arg.option(&mailType, 'm'))
    {
        if (mailType == "log")
            d_mailType = MailType::LOG;
        else 
        {
            d_mailType = MailType::OFF;
            if (mailType != "off")
                wmsg << "--mail " << mailType << " not supported: no mail is "
                                                            "sent" << endl;
        }
    }

    bool useSyslog = setSyslog();

    string verbosity;
    d_verbosity = d_arg.option(&verbosity, 'V') ?
                        stoul(verbosity)
                    :
                        s_defaultVerbosity;

    if (d_verbosity == 0)
        imsg.off();
    else if (useSyslog || not logName.empty())
        imsg.reset(d_msg);
    else
        wmsg << "--verbosity ignored: --syslog or --log not specified" << 
                                                                        endl;

    Msg::setVerbosity(d_verbosity);

    repeatOption();
    setRandomDelay();

    d_policyFilePath = Util::realPath(d_arg[0]);
}       










