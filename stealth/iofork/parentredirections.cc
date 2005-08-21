#include "iofork.ih"

void IOFork::parentRedirections()
{
    d_ins = new std::istream(
                new IFdStreambuf(d_out.readOnly())); //, 500));
    d_outs = new std::ostream(
                new OFdStreambuf(d_in.writeOnly())); //, 500));
}
