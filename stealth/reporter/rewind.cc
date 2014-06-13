#include "reporter.ih"

void Reporter::rewind()
{
    unsigned long currentSize = d_out.tellg();
    d_out.seekg(d_reinitSize, ios::beg);

    d_reinitSize = currentSize;
}

