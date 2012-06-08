#include "monitor.ih"

void Monitor::randomDelay()
{ 
    string delay;

    if (!d_arg.option(&delay, 'i'))
        return;

    if (!d_arg.option(0, "repeat"))
    {
        wmsg << "--random-interval ignored unless --repeat is specified" <<
                                                                        endl;
        return;
    }

    delay += '\n';                  // to make sure the istr doesn't fail
                                    // if only a number is read: no separating
                                    // ws at the end would cause istr.peek() 
                                    // to fail.

    istringstream istr(delay.c_str());

    istr >> s_delayInterval;

    if (istr.peek() == 'm')
        s_delayInterval *= 60;

    if (!istr || s_delayInterval < 0)
        fmsg << "Invalid interval for --random-interval" << endl;

    srandom(time(0));               // seed the random time generator
}





