#include "stealth.ih"

std::string Stealth::deniedMode(char const *request)
{
    ostringstream ostr;

    ostr << "Stealth daemon (pid = " << getpid() << "): `" << request << 
                "' not available in mode " << d_task;


    m2 << "ignored --rerun in mode " << d_task << endl;

    return ostr.str();
}
