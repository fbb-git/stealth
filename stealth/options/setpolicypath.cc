#include "options.ih"

void Options::setPolicyPath()
{
    if (d_ipc)
        return;
    
    d_policyFilePath = d_arg[0];
    
    Util::absPath(d_base, d_policyFilePath);
}
