#include "stealth.ih"

void Stealth::process(Mode request)
try
{
    (this->*(s_task.find(request)->second))();
}
catch (Mode)
{
    terminate();
}
