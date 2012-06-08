#include "monitor.ih"

void Monitor::reload()
{
    d_sorter.reset(   new ConfigSorter(d_arg[0]) );
    d_scanner->nScansReset();
    d_scanner->loadSkipFiles();
}


