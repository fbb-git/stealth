#include "options.ih"

void Options::setPolicyPath()
{
    if (d_ipc)
        return;
    
    d_policyPath = d_arg[0];
    
    Util::absPath(d_base, d_policyPath);
}
