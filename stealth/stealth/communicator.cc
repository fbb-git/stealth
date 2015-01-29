#include "stealth.ih"

void Stealth::communicator()
{
    LocalServerSocket uds(unixDomainSocket());

    uds.listen();

    do
    {
        int socket = uds.accept();      // accept a request

        IFdStream in(socket);           // stream to read the request from

        int request;                    // read te request
        if (not (in >> request).ignore(numeric_limits<int>::max(), '\n')) 
            request = UNKNOWN;

                                        // validate and prepare the req.
                                        // using the ...request() functions
                                        // when this succeeds, d_task holds
                                        // the requested mode
        d_result = (this->*s_request.find(  
                                    RunMode::validate(request)
                                )->second
                        )();

        if (d_result.empty())           // if the *request functions succeed
        {                               // d_result is empty, and the mode is
                                        // handled. Otherwise `remote' is 
                                        // informed about the reason of the
                                        // failure.
            d_command.notify();
            d_remote.wait();
        }
        
        OFdStream out(socket);
        out << d_result << endl;
    }
    while (not d_task.mode(TERMINATE));
}




//    while (d_task.mode() != TERMINATE)
//    {
//        int socket = uds.accept();       // accept a request
//
//        IFdStream in(socket);               // read the request
//        int request;
//        if (not (in >> request).ignore(1000, '\n')) 
//            request = UNKNOWN;
//
//                                            // validate and prepare the req.
//                                            // using the *request() functions
//        d_result = (this->*s_request.find(  
//                                    RunMode::validate(request)
//                                )->second
//                        )();
//
//        if (d_result.empty())               // if the *request functions fail
//        {                                   // d_result contains the reason
//                                            // otherwise:
//            d_chore.notify();               // indicate that another chore is
//            d_communicate.wait();           // pending and wait for the result
//        }
//
//        OFdStream out(socket);
//        out << d_result << endl;            // send the result to the client
//    }







