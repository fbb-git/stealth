#include "iofork.ih"

void IOFork::childRedirections()
{
    d_out.useForWritingTo(STDOUT_FILENO);
    d_in.useForReadingFrom(STDIN_FILENO);
}


