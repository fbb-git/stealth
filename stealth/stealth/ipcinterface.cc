#include "stealth.ih"

void Stealth::ipcInterface()
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

        d_ipc.wait();                   // wait until an IPC command can be
                                        // accepted

                                        // validate and prepare the req.
                                        // using the ...request() functions
                                        // when this succeeds, d_task holds
                                        // the requested mode
        d_answer = (this->*s_request.find(  
                                    RunMode::validate(request)
                                )->second
                        )();

        if (d_answer == "nop")
            d_answer.clear();           // command not requiring an operation
        else if (d_answer.empty())      // if the *request functions succeed
        {                               // d_answer is empty, and the mode is
                                        // handled. Otherwise `remote' is 
                                        // informed about the reason of the
                                        // failure.
            d_processor.notify();
            d_result.wait();
        }
        
        OFdStream out(socket);
        out << d_answer << endl;
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
//        d_answer = (this->*s_request.find(  
//                                    RunMode::validate(request)
//                                )->second
//                        )();
//
//        if (d_answer.empty())               // if the *request functions fail
//        {                                   // d_answer contains the reason
//                                            // otherwise:
//            d_chore.notify();               // indicate that another chore is
//            d_communicate.wait();           // pending and wait for the result
//        }
//
//        OFdStream out(socket);
//        out << d_answer << endl;            // send the result to the client
//    }







