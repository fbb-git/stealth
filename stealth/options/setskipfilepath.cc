#include "options.ih"

void Options::setSkipFilePath()
{
    if (not d_arg.option(&d_skipFilePath, 's'))
        return;

    if (d_ipc)
        fmsg << "--skip-files incompatible with IPC calls" << endl;
}
