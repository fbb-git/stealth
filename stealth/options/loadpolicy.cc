#include "options.ih"

void Options::loadPolicy()
{
    if (d_ipc)
        return;
    
    char buffer[PATH_MAX];

    string policyPath = d_arg[0];

    string base(getcwd(buffer, PATH_MAX));
    base += '/';
    
    Util::absPath(base, policyPath);

    d_policyFile = make_shared<PolicyFile>(policyPath, d_parsePolicy);

    ifstream policy;
    Exception::open(policy, policyPath);

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

