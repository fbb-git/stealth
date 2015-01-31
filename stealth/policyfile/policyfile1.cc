#include "policyfile.ih"

PolicyFile::PolicyFile(string const &policyPath, size_t parseOnly)
:
    d_policyPath(policyPath),
    d_parseOnly(parseOnly)
{
    reload();
}



