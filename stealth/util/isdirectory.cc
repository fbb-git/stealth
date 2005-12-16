#include "util.ih"

bool Util::isDirectory(string const &name)
{
    struct stat buffer;

    return !stat(name.c_str(), &buffer) && S_ISDIR(buffer.st_mode);
}
