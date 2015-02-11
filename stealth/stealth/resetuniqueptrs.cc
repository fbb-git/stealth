#include "stealth.ih"

void Stealth::resetUniquePtrs()
{
    string const &path = d_options.policyFilePath();

    if (access(path.c_str(), R_OK) != 0)
        fmsg << "cannot read policy file `" << path << '\'' << flush;

    d_policyFile.reset(new PolicyFile(path, d_options.parsePolicy()));

    d_stealthReport.reset(new StealthReport(d_policyFile->reportFile()));

    d_integrityScanner.reset(
            new IntegrityScanner(d_task, *d_policyFile, *d_stealthReport);

}
