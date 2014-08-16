#include "stealth.ih"

FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_task =
    {
        {RELOAD,           &Stealth::reload},
        {TERMINATE,        &Stealth::terminate},
        {INTEGRITY_SCAN,   &Stealth::integrityScan},
        {SUSPEND,          &Stealth::suspend},
        {RESUME,           &Stealth::resume},
        {INVALID,          &Stealth::invalid},
    };

FBB::LinearMap<size_t, Stealth::Action> Stealth::s_signalHandler =
    {
//        {SIGHUP,    &Stealth::rerunSignal},
//        {SIGUSR1,   &Stealth::suspendSignal},
//        {SIGUSR2,   &Stealth::resumeSignal},
//        {SIGPIPE,   &Stealth::reloadSignal},

        {SIGUSR1,   &Stealth::pidFileSignal},

        {SIGTERM,   &Stealth::terminateSignal},
        {SIGINT,    &Stealth::terminateSignal},
    };


//Stealth::Mode   Stealth::s_mode = ONCE;
//bool            Stealth::s_mainProcess = false;
//bool            Stealth::s_quit = false;
//bool            Stealth::s_keepAlive = false;
//size_t          Stealth::s_delayInterval = 0;
//size_t          Stealth::s_repeatInterval = 0;
//
