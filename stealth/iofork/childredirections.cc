#include "iofork.ih"

void IOFork::childRedirections()
{
    d_out.writtenBy(STDOUT_FILENO);
    d_in.readFrom(STDIN_FILENO);
}


