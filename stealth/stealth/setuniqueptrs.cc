#include "stealth.ih"

void Stealth::setUniquePtrs()
{
    d_policyFile.reset(new PolicyFile(d_options));  // the PolicyFile may 
                                                    // redefine some options

    d_report.reset(new Report(d_options, *d_policyFile));

    d_integrityScanner.reset(
        new IntegrityScanner(d_pending, d_options, *d_policyFile, *d_report)
    );

    setupFatalReport();

    d_logUnit.setupLogs(d_logReport);     // possibly redefine the log files

    m2 << "constructed the Integrity Scanner" << endl;
    m3 << "max. download size: " << d_options.maxSizeStr() << endl;
}
