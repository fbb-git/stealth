#include "options.ih"

int Options::setLog()
{
    if 
    (
        (d_cmdLineOption & LOG)           // already a command line option
        or
        not d_arg.option(&d_logName, 'L')
    )
        return 0;

    Util::absPath(d_base, d_logName);
    return LOG;
}
