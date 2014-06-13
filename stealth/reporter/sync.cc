#include "reporter.ih"

int Reporter::sync()
{
    return MultiStreambuf::pSync();
}
