#include "policyfile.ih"

void PolicyFile::insert(LinearMap &linMap, string const &line)
{
    if (s_firstWord << s_firstWord[2])      // fetch 'KEY definition'
    {
        string type = s_firstWord[1];

        m5 << type << " line: " << line << endl;
        linMap[s_firstWord[1]] = s_firstWord[2];      // store key and value
        m5 << type << " key: " << s_firstWord[1] <<
                  ", value: " << linMap[s_firstWord[1]] << endl;
        return;
    }
                                                // error on failure
    imsg << "Format error: ignored `" << line << "'\n";
}

