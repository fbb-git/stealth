#include "monitor.ih"

void Monitor::randomDelay()
{ 
    string delay;

    if (!Arg::instance().option(&delay, 'i'))
        return;

    if (!Arg::instance().option(0, "repeat"))
    {
        msg() << "--random-interval ignored unless --repeat is specified" <<
                                                                warning;
        return;
    }

    delay += "\n";                  // to make sure the istr doesn't fail
                                    // if only a number is read: no separating
                                    // ws at the end would cause istr.peek() 
                                    // to fail.

    istringstream istr(delay.c_str());

    istr >> s_delayInterval;

    if (istr.peek() == 'm')
        s_delayInterval *= 60;

    if (!istr || s_delayInterval < 0)
        msg() << "Invalid interval for --random-interval" << fatal;

    srandom(time(0));               // seed the random time generator
}





