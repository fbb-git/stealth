#include "policyfile.ih"

PolicyFile::PolicyFile(string const &policyPath)
:
    d_policyPath(policyPath)
{
    reload();
}



