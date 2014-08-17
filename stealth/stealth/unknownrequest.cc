#include "stealth.ih"

void Stealth::unkownRequest()
{
    ostringstream msg;
    msg << "ignored unknown request `" << d_ipc.requestText() << '\'';

    m2 << msg << endl;
    d_stealthLog << "STEALTH " << msg << endl;

    d_request = false;
}



