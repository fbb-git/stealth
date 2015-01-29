#include "stealth.ih"

std::string Stealth::deniedMode(char const *request)
{
    ostringstream ostr;

    ostr << "Stealth deamon " << getpid() << " in mode " << 
                d_task.modeName() << " cannot do " << request;


    m2 << "ignored --rerun in mode " << d_task.modeName() << endl;

    return ostr.str();
}
