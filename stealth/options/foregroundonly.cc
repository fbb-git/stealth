#include "options.ih"

void Options::foregroundOnly(char const *optionName) const
{
    if (not d_foreground)
        fmsg << "--" << optionName << " is only valid for a " << 
                        basename() << " foreground process" << noidl;
}
