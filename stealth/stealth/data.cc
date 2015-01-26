#include "stealth.ih"

FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_task =
    {
        {RELOAD,            &Stealth::reload},
        {TERMINATE,         &Stealth::terminate},
        {INTEGRITY_SCAN,    &Stealth::integrityScan},
        {SUSPEND,           &Stealth::suspend},
        {RESUME,            &Stealth::resume},
    };

    // possible incoming requests at the communicator
FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_request =
    {
        {LEAVE,             &Stealth::unknownRequest},
        {INTEGRITY_SCAN,    &Stealth::unknownRequest},
        {WAIT,              &Stealth::unknownRequest},

        {RERUN,             &Stealth::rerunRequest},
        {SUSPEND,           &Stealth::suspendRequest},
        {RESUME,            &Stealth::resumeRequest},
        {RELOAD,            &Stealth::reloadRequest},
        {TERMINATE,         &Stealth::terminateRequest},

        {UNKNOWN,           &Stealth::unknownRequest},
    };



