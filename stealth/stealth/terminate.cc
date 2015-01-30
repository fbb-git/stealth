#include "stealth.ih"

void Stealth::terminate()
{
    logMsg("terminates");
    d_integrityScanner->stop();
    d_result.notify();    
}
