#include "policyfile.ih"

PolicyFile::PolicyFile(Options &options)
:
    d_options(options)
{
    load();

    m2 << "(re)loaded policy file `" << d_options.policyFilePath() << '\'' << 
                                                                        endl;
}



