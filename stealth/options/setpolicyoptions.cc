#include "options.ih"

void Options::setPolicyOptions()
{
    setMail();                  // sets log-mail and no-mail
    setSkipFile();
 
    setTimestamp();
 
//    setVerbosity( setSyslog(), setLog() );
 
    setStdout();              // not with daemons

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
