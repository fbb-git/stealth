#include "stealthlog.ih"

StealthLog::StealthLog()
:
    ostream(this)       // initialize the ostream with the MultiStreambuf
{
    insert(d_stealthlog);                      // insertions go to the stealthlog stream

    if (Options::instance().verbose())
        insert(cerr);
}
