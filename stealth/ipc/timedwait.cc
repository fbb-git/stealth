#include "ipc.ih"

void IPC::timedWait()
{
    Options &options = Options::instance();

    if (options.repeat())
    {
        size_t waitSeconds = options.repeatInterval() + 
                             options.randomAddition();
        m2 << "Waiting for " << waitSeconds << " seconds" << endl;

        d_selector.setAlarm(options.repeatInterval() + 
                            options.randomAddition());
    }

    wait();
}
