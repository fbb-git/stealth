#include "options.ih"

void Options::setLog()
{
    if (d_arg.option(&d_logName, 'L'))
        Util::absPath((*d_policyFile)["BASE"], d_logName);
}
