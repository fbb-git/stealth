#include "scanner.h2"

void Scanner::scanLoop()
{
    bool        multi = Util::keepAlive();
    unsigned    nRuns = 0;

    do
    {
        nRuns++;

        Util::setAlarm();

        run();                  // run all tests

        mailReport();           // mail the report

        d_reporter.reinit();    // prepare for the next run.

        Util::wait();
    }
    while (Util::keepAlive());

    if (multi)
    {
        d_reporter 
            << "STEALTH was terminated after " << nRuns << " scans at " << 
                                    Util::date << endl << endl;
        mailReport();       // mail the report, no more hereafter
    }
}




