#include "stealth.ih"

void Stealth::policyDepDataMembers()
{
    d_policyFile.reset(   new PolicyFile(d_options.policyFilePath()) );

    d_stealthlog.open((*d_policyFile)["REPORT"]);

    d_integrityScanner.reset(
                                new IntegrityScanner(
                                        d_run, *d_policyFile, d_stealthlog
                                    )  
                            );
}


//    handleKeepAliveOption();                        // maybe not needed ??  
//    d_repeatInterval = d_options.repeatInterval();      
//    if (d_options.randomDelay()))
//        s_delayInterval = d_options.delayInterval();



