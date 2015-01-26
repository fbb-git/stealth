#include "stealth.ih"

void Stealth::contactPeer()
{
    if (not d_options.ipc())
        return false;

    LocalClientSocket lcs(d_options.runFile()); // open the unix domain socket
    int fd = lcs.socket();

    OFdStream out(fd);
    out << d_options.mode() << endl;        // send the requested mode

    IFdStream in(fd);
    string answer;                          // wait for the answer
    getline(in, answer);

    if (not answer.empty())                 // show the answer if something
        throw Exception() << answer;        // went wrong.
}



