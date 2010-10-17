#include "reporter.ih"

ostream &Reporter::error()
{
    setOnce();
    d_continue = false;
    return *this;
}





