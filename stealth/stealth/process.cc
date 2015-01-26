#include "stealth.ih"

void Stealth::process(Mode request)
try
{
    d_result.clear();
    d_communicate.set(0);

    (this->*(s_task.find(request)->second))();

    d_communicate.notify();
}
catch (Mode)
{
    terminate();
}
