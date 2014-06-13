#include "stealth.ih"

void Stealth::integrityScan()
{
    d_integrityScanner->run();

    if (d_run.interrupted())
        return;

    d_run.setMode(d_options.keepAlive() ? WAIT : LEAVE);
}
