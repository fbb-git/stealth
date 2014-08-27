#include "stealth.ih"

void Stealth::signalHandler(size_t signal)
{
    d_ipc.signaled();

    if (d_options.ipc())
    {
        d_ipc.request();                // retrieve the return message
        return;
    }
        
    d_request = true;                   // set to false by unknownRequest.

                                        // SIGUSR1 signals are retrieved from
                                        // the runfile. Other signals
                                        // (TERM, INT) terminate the daemon.
    (this->*s_request.find(
                signal == SIGUSR1 ? d_ipc.request() : TERMINATE
            )->second)();
}



