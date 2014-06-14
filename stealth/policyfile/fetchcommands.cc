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

//    char *cp = realpath((d_use["BASE"] + "/" + d_use["REPORT"]).c_str(), 0);
//    d_use["REPORT"] = cp;
//    free(cp);

    for(auto &entry: d_command)
        replaceDefines(entry);

    if (Options::instance().verboseOrJustParse())
    {
        for(auto &value: d_use)
            imsg << "USE " << value.first << ": " << value.second << endl;

        for (size_t idx = 0; idx != d_command.size(); ++idx)
           imsg << (idx + 1) << ": " << d_command[idx] << endl;

        if (Options::instance().parseConfigFile())
        {
            imsg << "Configuration file processed" << endl;
            throw 0;
        }
    }

    if (!ok)
        fmsg << "USE SSH ... entry missing in the configuration file" << endl;
}


