#include "stealth.ih"

void Stealth::integrityScan()
{
    d_stealthReport.scanHeader();

    if (d_options.dryrun())
        d_stealthReport << "--dry-run: integrity scan suppressed" << endl;
    else if (d_integrityScanner->run())
        m2 << "Integrity scan completed" << endl;
    else
        d_task.setMode(TERMINATE);
    
}




