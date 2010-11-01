#include "reporter.ih"

int Reporter::sync()
{
    d_hasMail = true;
    return MultiStreambuf::pSync();
}
