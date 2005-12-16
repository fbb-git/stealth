#include "reporter.ih"

ostream &Reporter::exit()
{
    setOnce();
    d_continue = false;

    return *this;
}





