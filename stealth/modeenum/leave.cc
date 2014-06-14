#include "modeenum.ih"

ostream &ModeEnum::leave(ostream &out)
{
    out << endl;
    throw LEAVE;
}
