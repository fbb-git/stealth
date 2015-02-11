#include "stealth.ih"

void Stealth::reload()
{
    d_report->timestamp("reloads its policy file", 
                        d_integrityScanner->nScans());

    if (d_options.dryrun())
        d_report << "--dry-run: reload suppressed" << endl;
    else
    {
        resetUniquePtrs();
        d_integrityScanner->startCommandShells();
    }

    autoScan("reload");
}




