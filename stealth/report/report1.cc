#include "report.ih"

Report::Report(Options &options, PolicyFile const &policyFile)
:
    fstream(policyFile["REPORT"], ios::out | ios::ate | ios::in),
    d_name(policyFile["REPORT"]),
    d_options(options),
    d_policyFile(policyFile)
{
    if (not good())
    {
        clear();
        open(d_name, ios::out | ios::in | ios::trunc);
    }

    if (not good())
        fmsg << "cannot write report file `" << d_name << '\'' << noidl;

    ostringstream headerTxt;
    headerTxt << "\n"
            "STEALTH (" << Icmbuild::version << ") started at " << 
            d_options.rfc2822() << '\n';

    d_headerLine = headerTxt.str();

    *this << d_headerLine << endl;

    refresh();
}





