#include "configsorter.ih"

ConfigSorter::ConfigSorter(string const &confFile)
:
    d_configfile(confFile),
    d_use(&s_defaultKeyword[0], &s_defaultKeyword[s_nDefaultKeywords])
{
    fetchCommands();

    string &base = d_use["BASE"];

    base += "/.";                           // the . is required by mkdir

    char const *cp = base.c_str();

    if (!Util::mkdir(cp) || chdir(cp))
        fmsg << "Can't chdir to `" << cp << '\'' << endl;

    base.resize(base.length() - 1);         // cut off the . again
}



