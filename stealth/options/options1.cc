#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_msg(&d_multiStreambuf),
    d_maxSizeStr("10M"),
    d_repeatInterval(numeric_limits<int>::max())
{
    requireSomeArgument();      // no args/options, then usage and ends.

    oldOptions();               // ends if --keep-alive or --suppress was 
                                // specified

    setMode();                  // sets d_mode and all bool mode indicators
    checkMode();                // ends if multiple/incompatible modes were
                                // set

    d_dryrun = d_arg.option(0, "dry-run");

    setCommandNr();             // sets run-command, (requires foreground).
    setParsePolicy();           // sets the policy file (requires foreground)

    loadPolicy();               // load the policy file and load configuration 
                               // options from the policy file into ArgConfig
                                
    setMail();                  // sets log-mail and no-mail
    setSkipFilePath();

    setTimestamp();

    setVerbosity( setSyslog(), setLog() );

    setStdout();
    setRepeat();
    setRandomDelay();
    setDownloadSize();

    if (not d_ipc)
    {
        m1 << "timestamps use " << 
            (d_timestamp == TIMESTAMPS ? "local time" : "UTC") << endl;
        d_policyFile->pathMsg();
    }
}       



