#include "stealth.ih"

void Stealth::reload()
{
    d_policyFile->reload();
    d_integrityScanner.reset( 
                new IntegrityScanner(*d_policyFile, *d_reporter) 
    );

    d_integrityScanner->preamble();

    // cerr << "RELOAD COMPLETED (" << d_policyFilePath << ")\n";
}


