#include "stealth.ih"

void Stealth::integrityScan()
{
    d_stealthLog.scanHeader();

    if (d_options.dryrun())
        d_stealthLog << "--dry-run: integrity scan suppressed" << endl;
    else
        d_integrityScanner->run();

//    if (d_task.interrupted())
//        return;

//    d_task.setMode(d_options.daemon() or d_options.repeat() ? WAIT : LEAVE);
}




