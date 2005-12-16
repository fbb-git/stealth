#include "scanner.ih"

void Scanner::setSentinel()
{
    ostringstream oss;

    oss << "EOC " << Util::date;
    d_sentinel = oss.str();
}
