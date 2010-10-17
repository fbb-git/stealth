#include "configsorter.ih"

void ConfigSorter::insert(HashString<string> &hash, Pattern &firstWord,
                            string const &line)
{
    if (firstWord << firstWord[2])      // fetch 'KEY definition'
    {
        string type = firstWord[1];

        msg() << type << " line: " << line << info;
        hash[firstWord[1]] = firstWord[2];      // store key and value
        msg() << type << " key: " << firstWord[1] <<
                  ", value: " << hash[firstWord[1]] << info;
        return;
    }
                                                // error on failure
    cerr << "Config line `" << line << "' invalid\n";
}

