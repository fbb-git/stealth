#include "monitor.ih"

void Monitor::startStealth()
{
    d_sorter.reset( new ConfigSorter(Arg::instance()[0]) );
    d_reporter.reset(new Reporter((*d_sorter)["REPORT"]));
    d_scanner.reset(new Scanner(*d_sorter, *d_reporter));

    handleKeepAliveOption();
    handleRepeatOption();
    randomDelay();                  // determine any random delay
}


