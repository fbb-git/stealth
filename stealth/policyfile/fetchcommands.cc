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

    if (Options::instance().verboseOrJustParse())
    {
        for(auto &value: d_use)
            m5 << "USE " << value.first << ": " << value.second << endl;

        for (size_t idx = 0; idx != d_command.size(); ++idx)
           m5 << (idx + 1) << ": " << d_command[idx] << endl;

        if (Options::instance().parseConfigFile())
        {
            m5 << "Configuration file processed" << endl;
            throw 0;
        }
    }

    if (!ok)
        fmsg << "USE SSH ... entry missing in the configuration file" << endl;
}


