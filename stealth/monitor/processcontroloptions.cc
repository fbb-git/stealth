#include "monitor.ih"

void Monitor::processControlOptions()
{
    contactOtherStealth();          // exits this process if another Stealth
                                    // must be contacted


    startStealth();                 // only if contactOtherStealth returns
}


