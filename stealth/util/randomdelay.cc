#include "util.h2"

void Util::randomDelay()
{ 
    string delay;

    if (!Arg::getInstance().option(&delay, 'i'))
        return;

    delay += "\n";                  // to make sure the istr doesn't fail
                                    // if only a number is read: no separating
                                    // ws at the end would cause istr.peek() 
                                    // to fail.

    istringstream istr(delay.c_str());

    istr >> s_delayInterval;

    if (istr.peek() == 'm')
        s_delayInterval *= 60;

    if (!istr || s_delayInterval < 0)
        throw Errno(-1, "Invalid interval for -i");

    srandom(time(0));               // seed the random time generator
}





