#include "msg.ih"

void Msg::setVerbosity(size_t verbosity)
{
        // switch off all mx streams exceeding verbosity
    switch (verbosity)
    {
        case 0:        
            m1.setstate(ios::failbit);
        case 1:
            m2.setstate(ios::failbit);
        case 2:
            m3.setstate(ios::failbit);
        case 3:
            m4.setstate(ios::failbit);
        case 4:
            m5.setstate(ios::failbit);
    }

        // switch on all mx streams up to verbosity
    switch (verbosity)
    {
        case 5:
            m5.clear();        
        case 4:
            m4.clear();        
        case 3:
            m3.clear();        
        case 2:
            m2.clear();        
        case 1:
            m1.clear();
    }
}






