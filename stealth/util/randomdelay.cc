#include "util.h2"

void Util::randomDelay()
{ 
    string delay;
    Arg::getInstance().option(&delay, 'i');

    delay += "\n";                  // to make sure the istr doesn't fail
                                    // if only a number is read: no separating
                                    // ws at the end would cause istr to fail.

    istringstream istr(delay.c_str());

    long interval;

    istr >> interval;

    if (istr.peek() == 'm')
        interval *= 60;

    if (!istr || interval < 0)
        throw Errno(-1, "Invalid interval for -i");


    srandom(time(0));               // seed the random time generator

    unsigned sleep_interval = static_cast<unsigned>(random() % interval);

    if (Arg::getInstance().option('d'))
        cerr << "Would have waited " << sleep_interval << " seconds\n"
             << "Randomly selected from " << interval << " seconds\n";
    else
        sleep(sleep_interval);
}





