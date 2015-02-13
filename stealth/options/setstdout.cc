#include "options.ih"

void Options::setStdout()
{
    if (d_arg.option('o') or d_ipc)
    {
        if (d_daemon)
            fmsg << "--stdout incompatible with --daemon" << noidl;

        d_stdout = true;
    }
}
