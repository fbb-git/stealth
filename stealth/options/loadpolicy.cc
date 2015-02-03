#include "options.ih"

void Options::loadPolicy()
{
    if (d_ipc)
        return;
    
    char buffer[PATH_MAX];

    d_policyFilePath = d_arg[0];

    string base(getcwd(buffer, PATH_MAX));
    base += '/';
    
    Util::absPath(base, d_policyFilePath);

    d_policyFile = make_shared<PolicyFile>(d_policyFilePath, d_parsePolicy);

    loadPolicyOptions();
}
