#include "arg.ih"

void Arg::initialize(char const *optstring, int argc, char **argv)
{
    if (s_arg)
        throw Errno("Arg::initialize(): already initialized");

    s_arg = new Arg(optstring, argc, argv);
}
