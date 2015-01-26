#include "stealth.ih"

string Stealth::unknownRequest()
{
    ostringstream msg;
    string ret("unknown request");
    msg << "received " << ret;

    m2 << msg << endl;
    d_stealthLog << msg << endl;

    return ret;
}



