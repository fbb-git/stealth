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
    
    setCommandNr();             // sets run-command, (requires foreground).
    setParsePolicy();           // sets the policy file (requires foreground)
                                                        
    loadConfigFile();           // load the config file into ArgConfig if 
                                // available

    setMail();                  // sets log-mail and no-mail
    setSkipFilePath();

    setVerbosity( setSyslog(), setLog() );

    setStdout();
    setRepeat();
    setRandomDelay();
    setDownloadSize();
            
    d_policyFilePath = Util::realPath(d_arg[0]);
}       











