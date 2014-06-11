#include "stealth.ih"

void Stealth::startup()
{
    d_policyFile.reset(   new PolicyFile(d_options.policyFilePath()) );
    d_reporter.reset(       new Reporter((*d_policyFile)["REPORT"])  );
    d_integrityScanner.reset(
                                new IntegrityScanner(
                                        *d_policyFile, *d_reporter
                                    )  
                            );

//    handleKeepAliveOption();                        // maybe not needed ??  
//    d_repeatInterval = d_options.repeatInterval();      
//    if (d_options.randomDelay()))
//        s_delayInterval = d_options.delayInterval();
}


