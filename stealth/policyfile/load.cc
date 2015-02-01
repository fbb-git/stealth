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

    base += '.';                            // the . is required by mkdir

    char const *cp = base.c_str();

    if (!Util::mkdir(cp) || chdir(cp))
        fmsg << "Can't chdir to `" << cp << '\'' << endl;

    base.resize(base.length() - 1);         // cut off the . again
}







