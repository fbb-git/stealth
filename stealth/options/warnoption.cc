#include "options.ih"

void Options::warnOption(char const *label) const
{
    wmsg << label << " with --" << s_ipc.find(d_mode)->second << endl;
}
