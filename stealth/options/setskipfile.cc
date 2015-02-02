#include "options.ih"

void Options::setSkipFile()
{
    if (not d_arg.option(&d_skipFile, 's'))
        return;

    if (d_arg.nArgs() == 0)
        fmsg << "--skip-files: missing skip-file or policy file" << endl;

    if (d_ipc)
        fmsg << "--skip-files incompatible with IPC calls" << endl;

    Util::absPath((*d_policyFile)["BASE"], d_skipFile);
}
