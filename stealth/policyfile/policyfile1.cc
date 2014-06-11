#include "policyfile.ih"

PolicyFile::PolicyFile(string const &confPath)
:
    d_confPath(confPath)
{
    reload();
}



