#include "options.ih"

void Options::setParsePolicy()
{
    mp.setstate(ios::failbit);
    if ((d_parsePolicy = d_arg.option('p')))
    {
        if (d_daemon or ipc())
            fmsg << "--parse-policy-file only available in a foreground "
                                                "process" << endl;

        if (d_parsePolicy > 1)      // -pp shows the analysis as well
            mp.clear();
    }
}
