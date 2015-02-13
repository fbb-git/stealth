#include "policyfile.ih"

void PolicyFile::chdirBase() const
{
    char const *base = d_use.find("BASE")->second.c_str();

    if (chdir(base) != 0)
        fmsg << "Can't chdir to `" << base << '\'' << noidl;
}

