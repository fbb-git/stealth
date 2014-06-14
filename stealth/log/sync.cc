#include "log.ih"

int Log::sync()
{
    return MultiStreambuf::pSync();
}
