#include "log.ih"

Log::Log()
:
    ostream(this)       // initialize the ostream with the MultiStreambuf
{
    insert(d_log);                      // insertions go to the log stream

    if (Options::instance().verbose())
        insert(cerr);
}
