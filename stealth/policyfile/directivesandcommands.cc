#include "policyfile.ih"

void PolicyFile::directivesAndCommands()
{
    for (int idx = 0, size = d_configfile.size(); idx != size; ++idx)
    {
        string line = d_configfile[idx];

        if (!(s_firstWord << line))           // can't match a first word
        {
            if (!(s_comment << line))
                imsg << "Ignored unrecognized line `" << line << '\'' << endl;
            continue;                             
        }

        if (s_firstWord[1] == "USE")
            insert(d_use, line);
        else if (s_firstWord[1] == "DEFINE")
            insert(d_define, line);
        else
        {
            imsg << "Regular command: `" << line << '\'' << endl;
            d_command.push_back(line);
        }
    }
}

