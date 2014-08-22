#include "ipc.ih"

void IPC::sendRequestor(string const &msg)
{
    write(msg);
    if (kill(d_requestorPid, SIGUSR1) == 0)
        m2 << "to pid " << d_requestorPid << ": " << msg << endl;
    else
        m2 << "could not signal requestor " << d_requestorPid << 
                                        " (" << msg << ')' << endl;

}
