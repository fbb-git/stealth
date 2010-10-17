#include "configsorter.ih"

// called from ConfigSorter()

void ConfigSorter::fetchCommands()
{
    Arg &arg = Arg::instance();

    if (arg.option('c'))
        Msg::setDisplay(Msg::INFO, cout);

    for (int idx = 0, n = d_configfile.size(); idx < n; ++idx)
    {
        string line = d_configfile[idx];

        if (!(s_firstWord << line))           // can't match a first word
        {
            if (!(s_comment << line))
                msg() << "No match for `" << line << '\'' << info;
            continue;                             
        }

        if (s_firstWord[1] == "USE")
            insert(d_use, s_firstWord, line);
        else if (s_firstWord[1] == "DEFINE")
            insert(d_define, s_firstWord, line);
        else
        {
            msg() << "Regular command: `" << line << '\'' << info;
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
            msg() << "USE " << begin->first << ": " << begin->second << info;

        for (int idx = 0; idx < static_cast<int>(d_command.size()); idx++)
           msg() << (idx + 1) << ": " << d_command[idx] << info;

        if (Arg::instance().option('c'))
        {
            msg() << "ConfigSorter file processed" << info;
            throw 1;
        }
    }

    if (!ok)
        msg() << "USE SSH ... entry missing in the configuration file" << 
                                                                        fatal;
}


