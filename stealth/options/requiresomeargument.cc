#include "options.ih"

void Options::requireSomeArgument()
{
    // --help and --version already handled by versionHelp, but if nothing
    // is requested on the command line help is also provided.

    if (
        d_arg.nArgs() == 0 && d_arg.nOptions() == 0 && 
        d_arg.nLongOptions() == 0
    )
    {
        usage(d_arg.basename());
        throw 0;
    }
}
