#include "scanner.h2"

void Scanner::setSentinel()
{
    ostringstream oss;

    oss << "EOC " << Util::date;
    d_sentinel = oss.str();
}
