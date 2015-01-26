#include "stealth.ih"

void Stealth::communicator()
{
    LocalServerSocket server(d_options,runFile(), Socket::UNLINK);

    server.listen();

    while (d_options.mode() != TERMINATE)
    {
        int socket = server.accept();       // accept a request

        IFdStream in(socket);
        Mode request;
        if (not (in >> request).ignore(1000, '\n')) // read the request
            request = UNKNOWN;

                                            // validate and prepare the req.
                                            // using the *request() functions
        d_result = (this->*s_request.find(  
                                    RunMode::validate(request)
                                )->second
                        )();

        if (d_result.empty())               // if the *request functions fail
        {                                   // d_result contains the reason
                                            // otherwise:
            d_chore.notify();               // indicate that another chore is
            d_communicate.wait();           // pending and wait for the result
        }

        OFdStream out(socket);
        out << d_result << endl;            // send the result to the client
    }
}

