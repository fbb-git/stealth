#include "scanner.h2"

void Scanner::removeLOG()
{
    string matched = d_firstWord[0];    // complete matched text

    if (matched.find("LOG") == 0)       // LOG at the beginning
    {
        unsigned pos = matched.find_first_not_of(" \t", 3);

        // got '=', so we got 'LOG ='
        // remove 'LOG =' and proceed.
        if (pos != string::npos && matched[pos] == '=')
        {
            dout("removed `LOG =', kept `" << matched.substr(pos + 1) << "'");
            d_firstWord.match(matched.substr(pos + 1));
        }
        else
            dout("LOG is (partial) logname in `" << matched << "'");
    }
    else
        dout("No `LOG =' in CHECK command `" << matched << "'");
}

