#include "options.ih"

Options::Options()
:
    d_arg(Arg::instance())
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

    if (imsg.setActive(d_arg.option('d')))
        imsg.reset(cerr);
    else if (imsg.setActive(d_arg.option('c')))
        imsg.reset(cout);

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

    d_runFile = d_arg[0];

    checkAction();

    repeatOption();
    setRandomDelay();

    d_reportToStdout = d_arg.option('o');
    
    char *cp = realpath(d_arg[0], 0);
    d_policyFilePath = cp;
    free(cp);
}       










