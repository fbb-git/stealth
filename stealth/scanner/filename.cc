#include "scanner.ih"

string Scanner::fileName(string const &name)
{
    string::size_type pos;

    pos = name.rfind("/");                  // name contains dir-separator ?

    return pos == string::npos ? name : name.substr(pos + 1);
}
