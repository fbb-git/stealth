#include "options.ih"

void Options::setSkipFilePath()
{
    if (not d_arg.option(&d_skipFilePath, 's'))
        return;

    if (d_arg.nArgs() == 0)
        fmsg << "--skip-files: missing skip-file or policy file" << endl;

    if (d_skipFilePath[0] != '/')
        fmsg << "--skip-files " << d_skipFilePath << 
                    ": must specify an absolute file name" << endl;

    if (d_ipc)
        fmsg << "--skip-files incompatible with IPC calls" << endl;
}
