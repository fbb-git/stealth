#include "options.ih"

void Options::loadPolicy()
{
    if (d_ipc)
        return;
    
    d_policyFilePath = d_arg[0];
    
    Util::absPath(d_base, d_policyFilePath);

    d_base = d_policyFilePath.substr(0, d_policyFilePath.rfind('/') + 1);

    d_policyFile = make_shared<PolicyFile>(d_policyFilePath, d_parsePolicy);

    loadPolicyOptions();
}
