#include "util.ih"

string Util::realPath(string const &path)
{
    char *cp = ::realpath(path.c_str(), 0);

    string ret = cp;
    free(cp);
    return ret;
}
