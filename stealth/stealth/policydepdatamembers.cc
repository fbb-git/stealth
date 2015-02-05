#include "stealth.ih"

void Stealth::policyDepDataMembers()
{
    d_policyFile = d_options.policyFile();

    d_policyFile->chdirBase();        

    d_stealthReport.open((*d_policyFile)["REPORT"]);

    d_integrityScanner = make_shared<IntegrityScanner>(
                                d_task, *d_policyFile, d_stealthReport
                            );
}


