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

    setMail();
    setSkipFilePath();
    setVerbosity( setSyslog(), setLog() );
    setStdout();
    setRepeat();
    setRandomDelay();
            
    d_policyFilePath = Util::realPath(d_arg[0]);
}       











