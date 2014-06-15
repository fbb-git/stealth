#include "stealthenums.ih"

ostream &StealthEnums::leave(ostream &out)
{
    out << endl;
    throw LEAVE;
}
