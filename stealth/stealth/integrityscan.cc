#include "stealth.ih"

void Stealth::integrityScan()
{
    d_report->scanHeader();

    if (d_options.dryrun())
    {
        *d_report << "--dry-run: would have performed an integrity scan" << 
                                                                        endl;
        return;
    }

    d_integrityScanner->run();
    m2 << "Integrity scan completed" << endl;
}




