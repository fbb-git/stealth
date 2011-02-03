#include "configsorter.ih"

void ConfigSorter::insert(HashString<string> &hash, string const &line)
{
    if (s_firstWord << s_firstWord[2])      // fetch 'KEY definition'
    {
        string type = s_firstWord[1];

        imsg << type << " line: " << line << endl;
        hash[s_firstWord[1]] = s_firstWord[2];      // store key and value
        imsg << type << " key: " << s_firstWord[1] <<
                  ", value: " << hash[s_firstWord[1]] << endl;
        return;
    }
                                                // error on failure
    cerr << "Config line `" << line << "' invalid\n";
}

