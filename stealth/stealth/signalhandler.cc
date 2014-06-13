#include "stealth.ih"

void Stealth::signalHandler(size_t signal)
{
    (this->*s_signalHandler.find(signal)->second)();
}
//    d_ipc.wakeup();       ?? already woke up...


