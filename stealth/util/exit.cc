#include "util.h2"

void Util::exit(int exitnr, char const *fmt, ...)
{
    va_list 
        list;

    va_start(list, fmt);

    vfprintf(stderr, fmt, list);
    cerr << endl;
    ::exit(1);
}
