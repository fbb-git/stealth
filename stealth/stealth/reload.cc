#include "stealth.ih"

void Stealth::reload()
{
    report("reloads its policy file");

    d_policyFile->reload();
    d_integrityScanner.reset( 
                new IntegrityScanner(*d_policyFile, *d_reporter) 
    );

    d_integrityScanner->startCommandShells();

    // cerr << "RELOAD COMPLETED (" << d_policyFilePath << ")\n";
}


