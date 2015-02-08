#include "options.ih"

string Options::getCwd()
{
    char buffer[PATH_MAX];
    string base(getcwd(buffer, PATH_MAX));
    base += '/';
    
    return base;
}
