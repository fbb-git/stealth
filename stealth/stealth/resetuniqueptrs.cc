#include "stealth.ih"

void Stealth::resetUniquePtrs()
{
    string const &path = d_options.policyFilePath();

    d_policyFile.reset(new PolicyFile(path, d_options.parsePolicy()));

    d_report.reset(new StealthReport(d_options, d_policyFile));

    d_logUnit.setupLogs(*d_stealthReport);

    d_integrityScanner.reset(
            new IntegrityScanner(d_task, *d_policyFile, *d_stealthReport);

}
