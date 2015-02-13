#include "stealth.ih"

// see also documentation/images/ipcinterface.jpg

void Stealth::ipcInterface()
try
{
    string const &udsName =  d_options.unixDomainSocket();

    m2 << "Unix Domain Socket: " << udsName << endl;

    LocalServerSocket uds(udsName);

    uds.listen();

    do
    {
        int socket = uds.accept();      // accept a request

        IFdStream in(socket);           // stream to read the request from
        OFdStream out(socket);          // stream to write answers to the 
                                        // ipc-stealth process to.
        if (incomingRequest(in, out))
        {
            d_ipc.wait();               // wait until an IPC command can be
                                        // accepted

            out << endl;                // all commands succeed: empty return
                                        // texts indicates so.
            notifyTask();
        }
    }
    while (not d_task.hasMode(TERMINATE));
}
catch (exception const &exc)
{
    ostringstream msg;
    msg << '\n' << exc.what() << "\n"
                       "    TERMINATING: exception in ipcInterface:\n";

    imsg << msg.str() << endl;
    *d_report << msg.str() << endl;
    d_report->mail();
    
    d_pending.setMode(TERMINATE);
    d_ipc.wait();
    notifyTask();
}
