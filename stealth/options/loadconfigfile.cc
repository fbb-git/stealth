#include "options.ih"

void Options::loadConfigFile()
{
    if (d_ipc)
        return;

    d_policyFilePath = Util::realPath(d_arg[0]);

    ifstream policy;
    Exception::open(policy, d_policyFilePath);

    string line;
    while (getline(policy, line) && line != "%%")   // find the %% separator
        ;

    if (line != "%%")                               // no separator?
        return;                                     // then done here

    TempStream tmpStream(User().homedir() + s_configFileBase);

    tmpStream << policy.rdbuf();                    // copy the long options
                                                    // into the temp. stream 

    tmpStream.close();                              

    d_arg.open(tmpStream.fileName());               // read the config file
}

