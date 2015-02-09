#include "stealth.ih"

void Stealth::openStealthReport()
try
{
    d_stealthReport.open((*d_policyFile)["REPORT"]);
}
catch (exception const &exc)
{
    d_fatal << exc.what() << leave;
}
