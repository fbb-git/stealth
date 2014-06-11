#include "integrityscanner.ih"

void IntegrityScanner::setSentinel()
{
    ostringstream oss;

    oss << "EOC " << DateTime();
    d_sentinel = oss.str();
}
