#include "reporter.ih"

// This function is called from standby(), and (re)inits the report file. It
// remembers its initial size, writes the header and sets `d_hasMail' to
// false. New entries inserted into the report file will automatically set
// `d_hasMail' to true.

void Reporter::reinit()
{
    imsg << "Reinit the reporter" << endl;

    d_out.clear();

    Stat stat(d_name);

    if (!stat)
        fmsg << "Can't stat " << d_name << endl;

    d_sizeAtConstruction = stat.size();

    imsg << "Reinit next report starts at " << d_sizeAtConstruction << endl;

    *this << "\n"
            "STEALTH (" << version << ") started at " << 
            DateTime() << "\n"
                          "\n";

    d_hasMail = false;
}



