#include "util.h2"

void Util::setAlarm()
{
    unsigned random_wait = 
        s_delayInterval ? 
            static_cast<unsigned>(random() % s_delayInterval)
        :
            0;

    if (Arg::getInstance().option('d'))
    {
        cerr << "Would have waited " << random_wait << " seconds\n"
             << "Randomly selected from " << s_delayInterval << 
            " seconds\n";
        random_wait = 0;
    }

    s_selector.setAlarm(s_repeatInterval + random_wait);
}
