#include "scanner.ih"

void Scanner::removeLOG()
{
    string matched = s_firstWord[0];    // complete matched text

    if (matched.find("LOG") == 0)       // LOG at the beginning
    {
        size_t pos = matched.find_first_not_of(" \t", 3);

        // got '=', so we got 'LOG ='
        // remove 'LOG =' and proceed.
        if (pos != string::npos && matched[pos] == '=')
        {
            msg() << "removed `LOG =', kept `" << 
                            matched.substr(pos + 1) << '\'' << info;
            s_firstWord.match(matched.substr(pos + 1));
        }
        else
            msg() << "LOG is (partial) logname in `" << matched << '\'' << 
                                                                        info;
    }
    else
        msg() << "No `LOG =' in CHECK command `" << matched << "'" << info;
}

