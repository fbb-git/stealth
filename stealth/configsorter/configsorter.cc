#include "configsorter.ih"

ConfigSorter::ConfigSorter(string const &confPath)
:
    d_confPath(confPath)
{
    reload();
}



