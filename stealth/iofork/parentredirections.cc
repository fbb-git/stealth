#include "iofork.ih"

void IOFork::parentRedirections()
{
    d_ins = new std::istream(
                new ifdnstreambuf(d_out.useForReading())); //, 500));
    d_outs = new std::ostream(
                new ofdnstreambuf(d_in.useForWriting())); //, 500));
}
