#include "options.ih"

void Options::setRandomDelay()
{ 
    string delay;

                                    // no option initializes to 0
    if (not (d_randomDelay = d_arg.option(&delay, 'i')))
        return;

    if (not d_repeat)
        fmsg << "--random-interval requires --repeat" << endl;

    d_delayInterval = checkM(delay, "random-interval");

    srandom(time(0));               // seed the random time generator
}
