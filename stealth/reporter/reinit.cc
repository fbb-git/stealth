#include "reporter.h2"

void Reporter::reinit()
{
    dout("Reinit the reporter");

    clear();

    struct stat statbuf;

    if (stat(d_name.c_str(), &statbuf))
        throw Errno((s_msg = "Can't stat " +  d_name).c_str());

    d_sizeAtConstruction = statbuf.st_size;

    dout("Reinit next report starts at " << d_sizeAtConstruction);

    *this << endl << endl
        << "STEALTH (" << Util::getVersion() << ") started at " << 
                                    Util::date << endl << endl;

    stat(d_name.c_str(), &statbuf);

    d_sizeBeyondHeader = tellp();

    dout("Size beyond header now: " << d_sizeBeyondHeader);
}


