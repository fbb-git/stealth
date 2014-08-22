#include "stealth.ih"

void Stealth::unknownRequest()
{
    ostringstream msg;
    msg << "received undefined request `" << d_ipc.requestText() << '\'';

    m2 << msg << endl;
    d_stealthLog << msg << endl;

    d_request = false;
}



