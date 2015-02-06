#include "stealth.ih"

void Stealth::ipcInterface()
try
{
    string const &udsName =  d_options.unixDomainSocket();

    m2 << "unix domain socket: " << udsName << endl;

    LocalServerSocket uds(udsName);

    uds.listen();

    do
    {
        int socket = uds.accept();      // accept a request

        IFdStream in(socket);           // stream to read the request from
        OFdStream out(socket);          // stream to write answers to the 
                                        // ipc-stealth process to.

        if (not incomingRequest(in, out))
            continue;

        d_ipc.wait();                   // wait until an IPC command can be
                                        // accepted

        out << endl;                    // all commands succeed: empty return
                                        // texts indicates so.

        notifyTask();
    }
    while (not d_task.hasMode(TERMINATE));
}
catch (exception const &exc)
{
    ostringstream msg;
    msg << '\n' << exc.what() << "\n"
                       "    caught exception in ipcInterface: TERMINATING\n";

    imsg << msg.str() << endl;
    d_stealthReport << msg.str() << endl;

    d_pending.setMode(TERMINATE);
    d_ipc.wait();
    notifyTask();
}
        













