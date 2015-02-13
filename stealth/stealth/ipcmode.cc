#include "stealth.ih"

bool Stealth::ipcMode()
{
    if (not d_options.ipc())
        return false;

    int fd;
    LocalClientSocket uds;

    try
    {
        uds.open(d_options.unixDomainSocket());
        fd = uds.connect();
    }
    catch (...)
    {
        throw Exception() << "can't connect to `" << 
                            d_options.unixDomainSocket() << '\'';
    }

    OFdStream out(fd);
    out << d_options.mode() << endl;        // send the requested mode

    IFdStream in(fd);
    string answer;                          // wait for the answer
    getline(in, answer);

    if (not answer.empty())                 // show the answer if something
        throw Exception() << answer;        // went wrong.

    return true;
}


