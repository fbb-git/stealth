#include "reporter.ih"

bool Reporter::hasMail() 
{
    cerr << d_out.tellp() << ", AND " << d_beginMail << endl;

    return d_out.tellp() > d_beginMail;
}

