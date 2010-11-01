#include "configsorter.ih"

// called from ConfigSorter()

void ConfigSorter::fetchCommands()
{
    Arg &arg = Arg::instance();

    if (arg.option('c'))
        imsg.reset(cout);

    for (int idx = 0, n = d_configfile.size(); idx < n; ++idx)
    {
        string line = d_configfile[idx];

        if (!(s_firstWord << line))           // can't match a first word
        {
            if (!(s_comment << line))
                imsg << "No match for `" << line << '\'' << endl;
            continue;                             
        }

        if (s_firstWord[1] == "USE")
            insert(d_use, s_firstWord, line);
        else if (s_firstWord[1] == "DEFINE")
            insert(d_define, s_firstWord, line);
        else
        {
            imsg << "Regular command: `" << line << '\'' << endl;
            d_command.push_back(line);
        }
    }

    bool    ok = d_use.count("SSH");

    for 
    (
        HashString<string>::iterator it = d_define.begin();
            it != d_define.end();
                it++
    )
        replaceDefines(it->second);

    for 
    (
        HashString<string>::iterator it = d_use.begin();
            it != d_use.end();
                it++
    )
        replaceDefines(it->second);

    for 
    (
        vector<string>::iterator it = d_command.begin();
            it != d_command.end();
                it++
    )
        replaceDefines(*it);

    if (arg.option("dc"))
    {
        for
        (
            HashString<string>::iterator
            begin = d_use.begin(), end = d_use.end();
                begin != end;
                    begin++
        )
            imsg << "USE " << begin->first << ": " << begin->second << endl;

        for (int idx = 0; idx < static_cast<int>(d_command.size()); idx++)
           imsg << (idx + 1) << ": " << d_command[idx] << endl;

        if (Arg::instance().option('c'))
        {
            imsg << "ConfigSorter file processed" << endl;
            throw 1;
        }
    }

    if (!ok)
        fmsg << "USE SSH ... entry missing in the configuration file" << endl;
}


