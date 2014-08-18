#include "stealth.ih"

void Stealth::integrityScan()
{
    d_stealthLog.scanHeader();

    if (d_options.dryrun())
        d_stealthLog << "--dry-run: integrity scan suppressed" << endl;
    else
        d_integrityScanner->run();

    if (d_run.interrupted())
        return;

    d_run.setMode(d_options.daemon() ? WAIT : LEAVE);
}
