#include "reporter.h2"

void Reporter::reset()
{
    flush();
    seekg(d_sizeAtConstruction, ios::beg);
}

