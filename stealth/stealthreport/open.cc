#include "stealthreport.ih"

void StealthReport::open(string const &name)
{
    d_stealthreport.open(name, ios::out | ios::ate | ios::in);

    if (not d_stealthreport)
    {
        d_stealthreport.clear();
        d_stealthreport.open(name, ios::out | ios::in | ios::trunc);
    }

    if (not d_stealthreport)
        throw Exception() << "cannot write report file `" << name << '\'';

    d_name = name;

    ostringstream headerTxt;
    headerTxt << "\n"
            "STEALTH (" << Icmbuild::version << ") started at " << 
            Options::instance().rfc2822() << '\n';

    d_headerLine = headerTxt.str();

    d_stealthreport << d_headerLine << endl;

    rdbuf(d_stealthreport.rdbuf());
}
