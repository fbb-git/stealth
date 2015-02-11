#include "stealthreport.ih"

void StealthReport::StealthReport(Options &options, string const &name)
:
    fstream(name, ios::out | ios::ate | ios::in),
    d_options(options)
{
    if (not good())
    {
        clear();
        open(name, ios::out | ios::in | ios::trunc);
    }

    if (not good)
        fmsg << "cannot write report file `" << name << '\'';

    d_name = name;

    ostringstream headerTxt;
    headerTxt << "\n"
            "STEALTH (" << Icmbuild::version << ") started at " << 
            d_options.rfc2822() << '\n';

    d_headerLine = headerTxt.str();

    *this << d_headerLine << endl;
}





