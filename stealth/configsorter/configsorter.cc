#include "configsorter.h2"

ConfigSorter::ConfigSorter(ConfigFile &configfile)
:
    d_configfile(configfile),
    d_use(&s_defaultKeyword[0], &s_defaultKeyword[s_nDefaultKeywords])
{
    fetchCommands();

    string base = d_use["BASE"] + "/.";

    char const *cp = base.c_str();

    if (!Util::mkdir(cp) || chdir(cp))
        Util::exit(1, "Can't chdir to `%s'", cp);
}
