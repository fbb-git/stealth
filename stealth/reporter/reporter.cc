#include "reporter.h2"

Reporter::Reporter(string const &name)
:
    fstream(name.c_str(), ios::out | ios::ate | ios::in),
    d_name(name)
{
    if (!*this)
    {
        clear();
        open(name.c_str(), ios::out | ios::in | ios::trunc);    // open if 
    }                                                   // construction fails:
                                                        // new file
    if (!*this)
        throw Errno((s_msg = "Can't open " +  name).c_str());

    reinit();
}





