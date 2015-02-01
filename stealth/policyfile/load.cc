#include "policyfile.ih"

void PolicyFile::load()
{
    d_configfile.open(d_policyPath);

    d_use = LinearMap(
                &s_defaultKeyword[0], &s_defaultKeyword[s_nDefaultKeywords]
            );

    d_define.clear();
    d_command.clear();

    fetchCommands();

    string &base = d_use["BASE"];

    base += '.';                        // the . is required by mkdir
    char const *cp = base.c_str();
    Util::mkdir(cp);
    base.pop_back();                    // cut off the . again

    chdirBase();
}







