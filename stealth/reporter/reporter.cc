#include "reporter.h2"

Reporter::Reporter(string const &name)
:
    fstream(name.c_str(), ios::out | ios::ate | ios::in)
{
    if (!*this)
    {
        clear();
        open(name.c_str(), ios::out | ios::in | ios::trunc);    // open if 
    }                                                   // construction fails:
                                                        // new file
    if (!*this)
        throw Errno((s_msg = "Can't open " +  name).c_str());

    struct stat statbuf;

    if (stat(name.c_str(), &statbuf))
        throw Errno((s_msg = "Can't stat " +  name).c_str());

    d_sizeAtConstruction = statbuf.st_size;

    *this << endl << endl
        << "STEALTH (" << Util::getVersion() << ") started at " << 
                             Util::date << endl << endl;

    stat(name.c_str(), &statbuf);

    d_sizeBeyondHeader = tellp();
}
