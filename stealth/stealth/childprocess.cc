#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon("/tmp/out", "/tmp/err");

    doChores();    

    throw 0;
}
