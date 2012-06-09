#include "monitor.ih"

void Monitor::reload()
{
    d_sorter->reload(d_sorterPath);
    d_scanner->nScansReset();
    d_scanner->loadSkipFiles();

    cerr << "RELOAD COMPLETED (" << d_sorterPath << ")\n";
}


