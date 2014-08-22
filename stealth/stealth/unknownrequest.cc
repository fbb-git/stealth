#include "stealth.ih"

void Stealth::unknownRequest()
{
    ostringstream msg;
    msg << "request `" << d_ipc.requestText() << "' not supported";

    m2 << msg << endl;
    d_stealthLog << msg << endl;

    d_request = false;
}



