#include "util.ih"

string Util::fullPath(string const &path)
{
    char *fullPath = realpath(path, 0);

    if (fullPath == 0)
        Errno(("Cannot determine full path for " + path).c_str());

    string ret(fullPath);
    free(fullPath);

    return ret;
}
