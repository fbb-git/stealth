#include "configsorter.h2"

void ConfigSorter::insert(StringHash<string> &hash, Pattern &firstWord,
                            string const &line)
{
    if (firstWord.match(firstWord[2]))          // fetch 'KEY definition'
    {
        string type = firstWord[1];

        dout(type << " line: " << line);
        hash[firstWord[1]] = firstWord[2];      // store key and value
        dout(type << " key: " << firstWord[1] << \
                  ", value: " << hash[firstWord[1]]);
        return;
    }
                                                // error on failure
    cerr << "Config line `" << line << "' invalid" << endl;
}

