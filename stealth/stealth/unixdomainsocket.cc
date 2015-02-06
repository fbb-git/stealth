#include "stealth.ih"

string Stealth::unixDomainSocket() const
{
    string unixDomainSocket = d_options.unixDomainSocket();

    Util::absPath((*d_policyFile)["BASE"], unixDomainSocket);

    return unixDomainSocket;
}
