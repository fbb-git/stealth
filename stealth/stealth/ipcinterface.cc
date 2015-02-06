#include "stealth.ih"

void Stealth::ipcInterface()
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

        int request;                    // read te request
        if (not (in >> request).ignore(numeric_limits<int>::max(), '\n')) 
            request = UNKNOWN;

        RunMode incoming;
        incoming.setMode(RunMode::validate(request));

        string answer = (this->*s_request.find(incoming.mode())->second)();

        if (not answer.empty())         // error or no operation (nop)
        {
            if (answer == "nop")
                answer.clear();

            out << answer << endl;
            continue;                   // no-action or error request:
                                        // read the next request
        }

        d_pending = incoming;

        d_ipc.wait();                   // wait until an IPC command can be
                                        // accepted

        out << endl;                    // all commands succeed: empty return
                                        // texts indicates so.

        d_task = d_pending;             // set the next request
        d_pending.setMode(UNKNOWN);     // clear the pending request

        d_job.notify();                 // notify processRequests (i.e., 
    }
    while (not d_task.hasMode(TERMINATE));
}
