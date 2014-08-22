#include "stealth.ih"

FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_task =
    {
        {RELOAD,            &Stealth::reload},
        {TERMINATE,         &Stealth::terminate},
        {INTEGRITY_SCAN,    &Stealth::integrityScan},
        {SUSPEND,           &Stealth::suspend},
        {RESUME,            &Stealth::resume},
    };

FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_request =
    {
        {RELOAD,            &Stealth::reloadRequest},
        {RERUN,             &Stealth::rerunRequest},
        {RESUME,            &Stealth::resumeRequest},
        {SUSPEND,           &Stealth::suspendRequest},
        {TERMINATE,         &Stealth::terminateRequest},
        {UNKNOWN,           &Stealth::unknownRequest},
    };



