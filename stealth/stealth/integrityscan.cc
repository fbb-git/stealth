#include "stealth.ih"

void Stealth::integrityScan()
{
    d_stealthLog.scanHeader();

    d_integrityScanner->run();

    if (d_run.interrupted())
        return;

    d_run.setMode(d_options.daemon() ? WAIT : LEAVE);
}
