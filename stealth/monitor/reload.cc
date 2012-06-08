#include "monitor.ih"

void Monitor::reload()
{
    d_sorter.reset(   new ConfigSorter(d_sorterPath) );
    d_scanner->nScansReset();
    d_scanner->loadSkipFiles();
}


