#include "options.ih"

extern string g_logName;

void Options::setPolicyOptions()
{
//     setMail();                  // sets log-mail and no-mail
//     setSkipFile();
// 
     setTimestamp();
 
// //    setVerbosity( setSyslog(), setLog() );
// //    setVerbosity(true, g_logName );
 
//    setStdout();              // not with daemons

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
