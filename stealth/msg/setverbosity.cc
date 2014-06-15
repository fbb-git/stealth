#include "msg.ih"

void Msg::setVerbosity(size_t verbosity)
{
        // switch off all mx streams exceeding verbosity
    switch (verbosity)
    {
        case 0:        
            m1.rdbuf(0);
        case 1:
            m2.rdbuf(0);
        case 2:
            m3.rdbuf(0);
        case 3:
            m4.rdbuf(0);
        case 4:
            m5.rdbuf(0);
    }

    streambuf *buf = imsg.rdbuf();

        // switch on all mx streams up to verbosity
    switch (verbosity)
    {
        case 5:
            m5.rdbuf(buf);        
        case 4:
            m4.rdbuf(buf);        
        case 3:
            m3.rdbuf(buf);        
        case 2:
            m2.rdbuf(buf);        
        case 1:
            m1.rdbuf(buf);
    }
}






