#include "configsorter.ih"

void ConfigSorter::fetchCommands()
{
    Pattern     firstWord("(\\S+)\\s+(.*)");

    for (int idx = 0, n = d_configfile.size(); idx < n; ++idx)
    {
        string line = d_configfile[idx];

        if (!(firstWord << line))           // can't match a first word
        {
            Util::debug() << "No match for `" << line << "'" << endl;
            continue;                             
        }

        if (firstWord[1] == "USE")
            insert(d_use, firstWord, line);
        else if (firstWord[1] == "DEFINE")
            insert(d_define, firstWord, line);
        else
        {
            Util::debug() << "Regular command: `" << line << "'" << endl;
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

    if (Arg::getInstance().option("dc"))
    {
        for
        (
            HashString<string>::iterator
            begin = d_use.begin(), end = d_use.end();
                begin != end;
                    begin++
        )
            cout << "USE " << begin->first << ": " << begin->second << endl;

        for (int idx = 0; idx < static_cast<int>(d_command.size()); idx++)
            cout << (idx + 1) << ": " << d_command[idx] << endl;

        if (Arg::getInstance().option('c'))
            Util::exit("ConfigSorter file processed"); 
    }

    if (!ok)
        Util::exit("USE SSH ... entry missing in the configuration file");
}
