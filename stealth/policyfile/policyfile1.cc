#include "policyfile.ih"

PolicyFile::PolicyFile(string const &policyPath, size_t parseOnly)
:
    d_policyPath(policyPath),
    d_parseOnly(parseOnly)
{
    load();

    m2 << "(re)loaded the policy file `" << d_policyPath << '\'' << endl;
}



