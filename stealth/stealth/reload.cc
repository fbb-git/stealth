#include "stealth.ih"

void Stealth::reload()
{
    timestamp("reloads its policy file");

    if (d_options.dryrun())
        *d_report << "--dry-run: reload suppressed" << endl;
    else
    {
        resetUniquePtrs();
        d_integrityScanner->startCommandShells();
    }

    autoScan("reload");
}




