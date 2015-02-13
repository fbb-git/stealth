#include "stealth.ih"

string Stealth::unknownRequest()
{
    ostringstream msg;

    string ret("unknown request");
    msg << "received " << ret;

    m2 << msg.str() << endl;
    *d_report << msg.str() << endl;

    return ret;
}



