#include "util.h2"

void Util::exit(int exitnr, char const *fmt, ...)
{
    va_list 
        list;

    if (!exitnr && Arg::getInstance().option('q'))
        return;

    va_start(list, fmt);

    vfprintf(stderr, fmt, list);
    cerr << endl;
    ::exit(1);
}
