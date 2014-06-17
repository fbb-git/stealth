#include "options.ih"

void Options::setSkipFilePath()
{
    if (not d_arg.option(&d_skipFilePath, 's'))
        return;

    if (ipc())
    {
        warnOption("--skip-files ignored");
        d_skipFilePath.clear();
    }
}
