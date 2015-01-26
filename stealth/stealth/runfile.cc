#include "stealth.ih"

string Stealth::unixDomainSocket() const
{
    string const &unixDomainSocket = d_options.unixDomainSocket();

    string ret = 
            unixDomainSocket.front() == '/' ?
                unixDomainSocket
            :
                (*d_policyFile)["BASE"] + unixDomainSocket;

    m2 << "unix domain socket uses `" << ret << '\'' << endl;

    return ret;
}
