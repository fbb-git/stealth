#include "configfile.h2"

bool ConfigFile::find(std::string const &param, std::string const *line) const
{
    unsigned len = param.length();

    bool
        ret =
            d_ignoreCase ?
                !strcasecmp
                (
                    param.c_str(), line->substr(0, len).c_str()
                )
            :
                line->find(param) == 0;

    if (!ret)
        return false;

    return line->length() == len || !isalnum((*line)[len]);
}   
