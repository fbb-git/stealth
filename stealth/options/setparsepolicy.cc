#include "options.ih"

void Options::setParsePolicy()
{
    mp.setstate(ios::failbit);
    if ((d_parsePolicy = d_arg.option('p')))
    {
        foregroundOnly("--parse-policy-file");

        if (d_parsePolicy > 1)      // -pp shows the analysis as well
            mp.clear();
    }
}
