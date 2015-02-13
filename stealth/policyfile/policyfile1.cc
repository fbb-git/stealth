#include "policyfile.ih"

PolicyFile::PolicyFile(Options &options)
:
    d_options(options)
{
    load();
}



