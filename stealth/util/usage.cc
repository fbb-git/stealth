#include "util.ih"

void usage(string const &stealth, string const &version, string const &year);

void Util::usage()
{
    ::usage(Arg::instance().basename(), version, year);

    throw ERROR;
}
