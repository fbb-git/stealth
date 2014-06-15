#include "stealthlog.ih"

void StealthLog::open(string const &name)
{
    d_name = name;
    d_stealthlog.open(name, ios::out | ios::ate | ios::in);

    if (not d_stealthlog)
    {
        d_stealthlog.clear();
        Exception::open(d_stealthlog, name, ios::out | ios::in | ios::trunc);    
    }

    ostringstream headerTxt;
    headerTxt << "\n"
            "STEALTH (" << Icmbuild::version << ") started at " << 
            DateTime().rfc2822() << '\n';

    d_headerLine = headerTxt.str();

    *this << d_headerLine << endl;
}
