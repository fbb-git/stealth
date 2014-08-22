#include "stealth.ih"

void Stealth::deniedMode(char const *request)
{
    ostringstream ostr;

    ostr << "Stealth deamon " << getpid() << " in mode " << 
                d_run.modeName() << " cannot do " << request;


    d_ipc.sendRequestor(ostr.str());

    m2 << "ignored --rerun in mode " << d_run.modeName() << endl;
}
