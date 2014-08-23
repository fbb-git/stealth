#include "options.ih"

size_t Options::checkM(string const &spec, char const *option) const
try
{
    size_t pos;
    size_t ret = stoul(spec, &pos);

    char ch = spec[pos];

    if (ch == 'm')
        ret *= 60;
    else if (isprint(ch))
        wmsg << '`' << ch << "' in --" << option << ' ' << spec << 
                                                        " ignored" << endl;
    return ret;
}
catch (...)
{
    fmsg << "Invalid --" << option << " specified" << endl;
    return 0;                   
}


