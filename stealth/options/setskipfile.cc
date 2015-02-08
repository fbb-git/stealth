#include "options.ih"

int Options::setSkipFile()
{
    if ((d_cmdLineOption & SKIP_FILE) or not d_arg.option(&d_skipFile, 's'))
        return 0;

    if (d_arg.nArgs() == 0)
        fmsg << "--skip-files: missing skip-file or policy file" << endl;

    if (d_ipc)
        fmsg << "--skip-files incompatible with IPC calls" << endl;

    Util::absPath(d_base, d_skipFile);

    return SKIP_FILE;
}
