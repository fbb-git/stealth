#include "stealth.ih"

void Stealth::setUniquePtrs()
{
    d_policyFile.reset(new PolicyFile(d_options));

    d_report.reset(new Report(d_options, *d_policyFile));

    d_logUnit.setupLogs(*d_report);

    d_integrityScanner.reset(
        new IntegrityScanner(d_pending, d_options, 
                             *d_policyFile, *d_report)
    );

}
