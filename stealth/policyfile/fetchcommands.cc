#include "policyfile.ih"

// called from PolicyFile()

void PolicyFile::fetchCommands()
{
    directivesAndCommands();

    bool ok = d_use.count("SSH");

    for(auto &entry: d_define)
        replaceDefines(entry.second);

    for(auto &entry: d_use)
        replaceDefines(entry.second);

    for(auto &entry: d_command)
        replaceDefines(entry);

    if (size_t parse = Options::instance().parsePolicyFile())
    {
        if (parse > 1)
            for(auto &value: d_use)
                mp << "USE " << value.first << ": " << value.second << endl;

        mp.clear();
        for (size_t idx = 0; idx != d_command.size(); ++idx)
           mp << (idx + 1) << ": " << d_command[idx] << endl;

        throw 0;
    }

    if (!ok)
        fmsg << "USE SSH ... entry missing in the configuration file" << endl;
}

