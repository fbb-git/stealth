#include "reporter.ih"

// This function is called from standby(), and (re)inits the report file. It
// remembers its initial size, writes the header and sets `d_hasMail' to
// false. New entries inserted into the report file will automatically set
// `d_hasMail' to true.

void Reporter::reinit()
{
    msg() << "Reinit the reporter" << info;

    d_out.clear();

    Stat stat(d_name);

    if (!stat)
        msg() << "Can't stat " << d_name << fatal;

    d_sizeAtConstruction = stat.size();

    msg() << "Reinit next report starts at " << d_sizeAtConstruction << info;

    *this << "\n"
            "STEALTH (" << version << ") started at " << 
            DateTime() << "\n"
                          "\n";

    d_hasMail = false;
}



