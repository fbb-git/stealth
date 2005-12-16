#include "util.ih"

void Util::exit(char const *fmt, ...)
{
    va_list list;
    va_start(list, fmt);

    vfprintf(stderr, fmt, list);
    cerr << endl;
    va_end(list);

    throw ERROR;    // ::exit(1);
}
