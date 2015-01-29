#include "stealth.ih"

FBB::LinearMap<Stealth::Mode, Stealth::Task> Stealth::s_task =
    {
        {RELOAD,            &Stealth::reload},
        {TERMINATE,         &Stealth::terminate},
        {INTEGRITY_SCAN,    &Stealth::startScan},
        {SUSPEND,           &Stealth::suspend},
        {RESUME,            &Stealth::resume},
        {RERUN,             &Stealth::rerun},
    };

    // possible incoming requests at the communicator
FBB::LinearMap<Stealth::Mode, Stealth::Action> Stealth::s_request =
    {
        {INTEGRITY_SCAN,    &Stealth::unknownRequest},

        {RERUN,             &Stealth::rerunRequest},
        {SUSPEND,           &Stealth::suspendRequest},
        {RESUME,            &Stealth::resumeRequest},
        {RELOAD,            &Stealth::reloadRequest},
        {TERMINATE,         &Stealth::terminateRequest},

        {UNKNOWN,           &Stealth::unknownRequest},
    };



