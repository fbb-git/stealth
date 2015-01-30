#include "stealth.ih"

void Stealth::integrityScan()
{
    d_stealthLog.scanHeader();

    if (d_options.dryrun())
        d_stealthLog << "--dry-run: integrity scan suppressed" << endl;
    else
        d_integrityScanner->run();

    m2 << "Integrity scan completed" << endl;
}




