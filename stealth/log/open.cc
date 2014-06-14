#include "log.ih"

void Log::open(string const &name)
{
    d_name = name;
    d_log.open(name, ios::out | ios::ate | ios::in);

    if (not d_log)
    {
        d_log.clear();
        Exception::open(d_log, name, ios::out | ios::in | ios::trunc);    
    }

    ostringstream headerTxt;
    headerTxt << "\n"
            "STEALTH (" << Icmbuild::version << ") started at " << 
            DateTime().rfc2822() << '\n';

    d_headerLine = headerTxt.str();

    *this << d_headerLine << endl;
}
