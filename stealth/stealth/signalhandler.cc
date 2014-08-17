#include "stealth.ih"

void Stealth::signalHandler(size_t signal)
{
    d_request = true;                   // set to false by unknownRequest.

    (this->*s_request.find(
                signal == SIGUSR1 ? d_ipc.request() : TERMINATE
            )->second)();
}



