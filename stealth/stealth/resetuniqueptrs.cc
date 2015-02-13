#include "stealth.ih"

void Stealth::resetUniquePtrs()
{
    string const &path = d_options.policyFilePath();

    d_policyFile.reset(new PolicyFile(path, d_options.parsePolicy()));

    d_report.reset(new StealthReport(d_options, *d_policyFile));

    d_logUnit.setupLogs(*d_report);

    d_integrityScanner.reset(
        new IntegrityScanner(d_pending, d_options, 
                             *d_policyFile, *d_report)
    );
}
