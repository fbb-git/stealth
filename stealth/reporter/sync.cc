#include "reporter.ih"

int Reporter::sync()
{
    d_hasMail = true;

    int ret = MultiStreambuf::sync();
    if (!d_continue)
        throw Util::ERROR;

    return ret;
}
