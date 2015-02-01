#include "options.ih"

void Options::setRepeat()
{
    string value;

    if (not (d_repeat = d_arg.option(&value, "repeat")))
        return;

    if (d_ipc)
        fmsg << "--repeat not available in IPC modes" << endl;

    d_repeatInterval = checkM(value, "repeat");  

    if (d_repeatInterval == 0)
        wmsg << "--repeat 0: no repeated integrity scans" << endl; 

    if (d_repeatInterval > static_cast<size_t>(numeric_limits<int>::max()))
        d_repeatInterval = numeric_limits<int>::max();
}


