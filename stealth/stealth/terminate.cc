#include "stealth.ih"

void Stealth::terminate()
{
    logMsg("terminates");
    d_integrityScanner->stop();
    endScanner();
    d_result.notify();    
}
