#include "stealth.ih"

void Stealth::policyDepDataMembers()
{
    d_policyFile = make_shared<PolicyFile>(d_options.policyFilePath());

    d_stealthLog.open((*d_policyFile)["REPORT"]);

    d_integrityScanner = make_shared<IntegrityScanner>(
                                d_task, *d_policyFile, d_stealthLog
                            );
}


