#include "stealth.ih"

bool Stealth::incomingRequest(istream &in, ostream &out)
{
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
        return false;               // no-action or error request:
                                    // read the next request
    }

    d_pending = incoming;
    return true;
}
