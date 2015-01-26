#include "stealth.ih"

std::string Stealth::deniedMode(char const *request)
{
    ostringstream ostr;

    ostr << "Stealth deamon " << getpid() << " in mode " << 
                d_run.modeName() << " cannot do " << request;


    m2 << "ignored --rerun in mode " << d_run.modeName() << endl;

    return ostr.str();
}
