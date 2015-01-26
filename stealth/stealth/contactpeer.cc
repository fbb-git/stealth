#include "stealth.ih"

bool Stealth::contactPeer()
try
{
    if (not d_options.ipc())
        return false;
                                            // open the unix domain socket
    LocalClientSocket lcs(d_options.unixDomainSocket()); 
    int fd = lcs.connect();

    OFdStream out(fd);
    out << d_options.mode() << endl;        // send the requested mode

    IFdStream in(fd);
    string answer;                          // wait for the answer
    getline(in, answer);

    if (not answer.empty())                 // show the answer if something
        throw Exception() << answer;        // went wrong.

    return true;
}
catch (...)
{
    throw Exception() << "can't connect to `" << 
                            d_options.unixDomainSocket() << '\'';
}

