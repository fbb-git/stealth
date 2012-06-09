#include "monitor.ih"

void Monitor::reload()
{
    d_sorter->reload();
    d_scanner.reset( new Scanner(*d_sorter, *d_reporter) );

    // ->nScansReset();
    // d_scanner->loadSkipFiles();

    d_scanner->preamble();

    cerr << "RELOAD COMPLETED (" << d_sorterPath << ")\n";
}


