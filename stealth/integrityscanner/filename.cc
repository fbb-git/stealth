#include "integrityscanner.ih"

string IntegrityScanner::fileName(string const &name)
{
    string::size_type pos;

    pos = name.rfind("/");                  // name contains dir-separator ?

    return pos == string::npos ? name : name.substr(pos + 1);
}
