#include "options.ih"

void Options::setConfigOptions()
{
    setMail();                  // sets log-mail and no-mail
    setSkipFile();

    setLog();
    setTimestamp();

    setSyslog();

    setVerbosity();
    setStdout();

    setRepeat();
    setRandomDelay();
    setDownloadSize();
}
