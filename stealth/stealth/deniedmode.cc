#include "stealth.ih"

std::string Stealth::deniedMode(char const *request)
{
    ostringstream ostr;

    ostr << "Stealth deamon (pid = " << getpid() << "): `" << request << 
                "' not available in mode " << d_task.modeName();


    m2 << "ignored --rerun in mode " << d_task.modeName() << endl;

    return ostr.str();
}
