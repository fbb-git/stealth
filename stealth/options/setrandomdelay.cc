#include "options.ih"

void Options::setRandomDelay()
{ 
    string delay;

                                    // no option initializes to 0
    if (not (d_randomDelay = d_arg.option(&delay, 'i')))
        return;

    if (not d_repeat)
    {
        wmsg << "--random-interval requires --repeat" << endl;
        return;
    }

    try
    {
        size_t pos;
        d_delayInterval = stoul(delay, &pos);

        char ch = delay[pos];

        if (ch == 'm')
            d_delayInterval *= 60;
        else if (isprint(ch))
            wmsg << '`' << ch << "' character following --random-interval " <<
                    d_delayInterval << " ignored" << endl;
    }
    catch (...)
    {
        fmsg << "Invalid --random-interval specified" << endl;
    }

    srandom(time(0));               // seed the random time generator
}
