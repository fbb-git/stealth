#include "reporter.ih"

// This function is called from standby(), and (re)inits the report file. It
// remembers its initial size, writes the header and sets `d_hasMail' to
// false. New entries inserted into the report file will automatically set
// `d_hasMail' to true.

void Reporter::reinit()
{
    Util::debug() << "Reinit the reporter" << endl;

    d_out.clear();

    struct stat statbuf;

    if (stat(d_name.c_str(), &statbuf))
        throw Errno("Can't stat ") << insertable << d_name << throwable;

    d_sizeAtConstruction = statbuf.st_size;

    Util::debug() << "Reinit next report starts at " << 
                                            d_sizeAtConstruction << endl;

    *this << "\n"
            "STEALTH (" << Util::getVersion() << ") started at " << 
            Util::date << "\n" << endl;

    d_hasMail = false;
}


