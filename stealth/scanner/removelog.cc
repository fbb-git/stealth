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
            Util::debug() << "removed `LOG =', kept `" << 
                            matched.substr(pos + 1) << "'\n";
            s_firstWord.match(matched.substr(pos + 1));
        }
        else
            Util::debug() << "LOG is (partial) logname in `" << 
                                                    matched << "'\n";
    }
    else
        Util::debug() << "No `LOG =' in CHECK command `" << matched << "'" <<
                                                                        "\n";
}

