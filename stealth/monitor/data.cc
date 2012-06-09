#include "monitor.ih"

Monitor::Mode   Monitor::s_mode = ONCE;
Selector        Monitor::s_selector;
bool            Monitor::s_mainProcess = false;
bool            Monitor::s_quit = false;
bool            Monitor::s_keepAlive = false;
size_t          Monitor::s_delayInterval = 0;
size_t          Monitor::s_repeatInterval = 0;

    // Update this array if Mode definitions in monitor.h change
char const *const Monitor::s_modeID[] = 
    {
        "ONCE",
        "KEEP",
        "TERMINATE",
        "TERMINATED",
        "SUPPRESS",
        "SUPPRESSED",
        "RELOAD"
    };
