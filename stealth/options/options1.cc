#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_msg(&d_multiStreambuf),
    d_maxSizeStr("10M"),
    d_repeatInterval(numeric_limits<int>::max())
{
    requireSomeArgument();

    oldOptions();

    setMode();
    checkMode();
    
    setCommandNr();
    setParsePolicy();
                                                        
    loadConfigFile();

    setStdout();
    setLog();
    setMail();
    setSkipFilePath();
    setVerbosity( setSyslog() );
    setRepeat();
    setRandomDelay();
            
    d_policyFilePath = Util::realPath(d_arg[0]);
}       











