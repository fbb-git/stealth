#include "integrityscanner.ih"

void IntegrityScanner::removeLOG()
{
    string matched = s_firstWord[0];    // complete matched text

    if (matched.find("LOG") == 0)       // LOG at the beginning
    {
        size_t pos = matched.find_first_not_of(" \t", 3);

        // got '=', so we got 'LOG ='
        // remove 'LOG =' and proceed.
        if (pos != string::npos && matched[pos] == '=')
        {
            m3 << "removed `LOG =', kept `" << 
                            matched.substr(pos + 1) << '\'' << endl;
            s_firstWord.match(matched.substr(pos + 1));
        }
        else
            m3 << "LOG is (partial) logname in `" << matched << '\'' << 
                                                                        endl;
    }
    else
        m3 << "No `LOG =' specified in CHECK command `" << matched << "'" << 
                                                                        endl;
}

