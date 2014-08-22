#include "stealth.ih"

void Stealth::policyDepDataMembers()
{
    d_policyFile.reset(   new PolicyFile(d_options.policyFilePath()) 
                        );

    d_stealthLog.open((*d_policyFile)["REPORT"]);

    d_integrityScanner.reset(
                            new IntegrityScanner(
                                    d_run, *d_policyFile, d_stealthLog
                                )  
                            );

}


