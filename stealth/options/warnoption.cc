#include "options.ih"

void Options::warnOption(char const *label) const
{
    wmsg << label << " with --" << s_modeInfo.find(d_mode)->second.modeTxt << 
                                                                        endl;
}
