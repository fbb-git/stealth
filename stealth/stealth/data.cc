#include "stealth.ih"

FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_task =
    {
        {RELOAD,            &Stealth::reload},
        {TERMINATE,         &Stealth::terminate},
        {INTEGRITY_SCAN,    &Stealth::integrityScan},
        {SUSPEND,           &Stealth::suspend},
        {RESUME,            &Stealth::resume},
    };

FBB::LinearMap<Mode, Stealth::Action> Stealth::s_request =
    {
        {RELOAD,            &Stealth::reloadRequest},
        {RERUN,             &Stealth::rerunRequest},
        {RESUME,            &Stealth::resumeRequest},
        {SUSPEND,           &Stealth::suspendRequest},
        {TERMINATE,         &Stealth::terminateRequest},
        {UNKOWN,            &Stealth::unkownRequest},
    };


//Stealth::Mode   Stealth::s_mode = ONCE;
//bool            Stealth::s_mainProcess = false;
//bool            Stealth::s_quit = false;
//bool            Stealth::s_keepAlive = false;
//size_t          Stealth::s_delayInterval = 0;
//size_t          Stealth::s_repeatInterval = 0;
//





