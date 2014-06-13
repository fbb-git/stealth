#include "reporter.ih"

void Reporter::rewind()
{
    unsigned long currentSize = d_out.tellg();
    d_out.seekg(d_sizeAtConstruction, ios::beg);

cerr << "Reporter::rewind reports out.good(): " << d_out.good() <<
        " at pos. " << d_out.tellg() << '\n';

    d_sizeAtConstruction = currentSize;
    d_hasMail = false;
}

