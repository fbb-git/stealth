#include "options.ih"

void Options::reloadPolicy()
{
    d_policyFile->reload();

    loadPolicyOptions();            // reload the options in the policy file
    setPolicyOptions();
}
