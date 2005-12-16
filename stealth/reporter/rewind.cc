#include "reporter.ih"

void Reporter::rewind()
{
    d_out.seekg(d_sizeAtConstruction, ios::beg);
}

