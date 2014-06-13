#include "stealth.ih"

void Stealth::childProcess()
{
    prepareDaemon("/tmp/out", "/tmp/err");

    performTasks();    

    throw 0;
}
