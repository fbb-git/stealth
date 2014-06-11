#include "stealth.ih"

void Stealth::reload()
{
    d_configSorter->reload();
    d_integrityScanner.reset( 
                new IntegrityScanner(*d_configSorter, *d_reporter) 
    );

    d_integrityScanner->preamble();

    // cerr << "RELOAD COMPLETED (" << d_configSorterPath << ")\n";
}


