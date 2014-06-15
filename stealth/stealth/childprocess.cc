#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon();

    doChores();    

    throw 0;
}
