#include "reporter.ih"

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


