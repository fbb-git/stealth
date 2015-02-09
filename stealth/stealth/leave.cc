#include "stealth.ih"

ostream &leave(ostream &out)
{
    out << endl;
    throw StealthEnums::Leave();
}
