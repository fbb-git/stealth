#include "options.ih"

void Options::setRepeat()
{
    string value;

    if (not (d_repeat = d_arg.option(&value, "repeat")))
        return;

    if (d_ipc)
        fmsg << "--repeat not available in IPC modes" << endl;

    try
    {
        d_repeatInterval = stoul(value);    // value 0: wait indefinite
    }
    catch (...)
    {
        fmsg << "--repeat requires <seconds> until next run" << endl;
    }

    if (d_repeatInterval < s_shortestRepeatInterval)
    {
        wmsg << "`--repeat " << d_repeatInterval << 
                "' changed to: `--repeat " << s_shortestRepeatInterval <<
                                                          '\'' << endl;
        d_repeatInterval = s_shortestRepeatInterval;
    }
    else if (d_repeatInterval > 
                    static_cast<size_t>(numeric_limits<int>::max()))
        d_repeatInterval = numeric_limits<int>::max();
}


