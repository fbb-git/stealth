#include "stealthreport.ih"

StealthReport::StealthReport(Options &options, PolicyFile const &policyFile)
:
    fstream(options.policyFilePath(), ios::out | ios::ate | ios::in),
    d_options(options),
    d_policyFile(policyFile)
{
    d_name =options.policyFilePath();

    if (not good())
    {
        clear();
        open(d_name, ios::out | ios::in | ios::trunc);
    }

    if (not good())
        fmsg << "cannot write report file `" << d_name << '\'';

    ostringstream headerTxt;
    headerTxt << "\n"
            "STEALTH (" << Icmbuild::version << ") started at " << 
            d_options.rfc2822() << '\n';

    d_headerLine = headerTxt.str();

    *this << d_headerLine << endl;
}





