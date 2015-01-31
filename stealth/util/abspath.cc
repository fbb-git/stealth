#include "util.ih"

void Util::absPath(string const &base, string &fileName)
{
    if (fileName.front() != '/')
        fileName = realPath(base + fileName);
}
