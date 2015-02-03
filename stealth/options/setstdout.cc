#include "options.ih"

void Options::setStdout()
{
    if (d_arg.option('o') or d_ipc)
    {
        if (d_daemon)
            fmsg << "--stdout incompatible with --daemon" << endl;

        d_stdout = true;
        d_multiStreambuf->insert(cout);
    }
}
