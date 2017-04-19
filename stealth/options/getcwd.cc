#include "options.ih"

string Options::getCwd()
{
    string base;

    if (char *buffer = getcwd(0, 0))
    {
        (base = buffer) += '/';
        free(buffer);
    }

    return base;
}
