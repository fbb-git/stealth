#include "scanner.ih"

void Scanner::setSentinel()
{
    ostringstream oss;

    oss << "EOC " << DateTime();
    d_sentinel = oss.str();
}
