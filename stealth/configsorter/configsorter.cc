#include "configsorter.ih"

ConfigSorter::ConfigSorter(char const *confFile)
:
    d_configfile(confFile),
    d_use(&s_defaultKeyword[0], &s_defaultKeyword[s_nDefaultKeywords])
{
    fetchCommands();

    string base = d_use["BASE"] + "/.";

    char const *cp = base.c_str();

    if (!Util::mkdir(cp) || chdir(cp))
        msg() << "Can't chdir to `" << cp << '\'' << fatal;
}
