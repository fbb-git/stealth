#include "stealth.ih"

void Stealth::startup()
{
    d_configSorter.reset(   new ConfigSorter(d_options.configSorterPath()) );
    d_reporter.reset(       new Reporter((*d_configSorter)["REPORT"])  );
    d_integrityScanner.reset(
                                new IntegrityScanner(
                                        *d_configSorter, *d_reporter
                                    )  
                            );

//    handleKeepAliveOption();                        // maybe not needed ??  
//    d_repeatInterval = d_options.repeatInterval();      
//    if (d_options.randomDelay()))
//        s_delayInterval = d_options.delayInterval();
}


