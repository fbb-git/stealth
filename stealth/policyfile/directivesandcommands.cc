#include "policyfile.ih"

void PolicyFile::directivesAndCommands()
try
{
    ConfigFile configfile(d_policyPath);

    for (size_t idx = 0, size = configfile.size(); idx != size; ++idx)
    {
        string line = configfile[idx];

        if (line == "%%")
        {
            loadOptions(configfile, idx + 1);
            return;
        }

        if (!(s_firstWord << line))         // can't match a first word
        {
            if (!(s_comment << line))
                wmsg << "Ignored unrecognized line `" << line << '\'' << endl;
            continue;                             
        }

        if (s_firstWord[1] == "USE")
            insert(d_use, line);
        else if (s_firstWord[1] == "DEFINE")
            insert(d_define, line);
        else
        {
            mp << "Regular command: `" << line << '\'' << endl;
            d_command.push_back(line);
        }
    }
}
catch (exception const &exc)
{
    fmsg << exc.what() << endl;
}
