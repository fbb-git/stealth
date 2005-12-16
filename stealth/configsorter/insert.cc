#include "configsorter.ih"

void ConfigSorter::insert(HashString<string> &hash, Pattern &firstWord,
                            string const &line)
{
    if (firstWord << firstWord[2])      // fetch 'KEY definition'
    {
        string type = firstWord[1];

        Util::debug() << type << " line: " << line << endl;
        hash[firstWord[1]] = firstWord[2];      // store key and value
        Util::debug() << type << " key: " << firstWord[1] <<
                  ", value: " << hash[firstWord[1]] << endl;
        return;
    }
                                                // error on failure
    cerr << "Config line `" << line << "' invalid" << endl;
}

