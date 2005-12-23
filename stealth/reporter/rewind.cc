#include "reporter.ih"

void Reporter::rewind()
{
    unsigned long currentSize = d_out.tellg();
    d_out.seekg(d_sizeAtConstruction, ios::beg);

    d_sizeAtConstruction = currentSize;
    d_hasMail = false;
}

