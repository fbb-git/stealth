#include "options.ih"

void Options::reloadPolicy()
{
    d_policyFile->reload();
    loadPolicyOptions();
    setPolicyOptions();
}
