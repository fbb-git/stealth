#ifndef INCLUDED_MSG_
#define INCLUDED_MSG_

#include <ostream>

class Msg: public std::ostream
{
    public:
        Msg();                  // msgs are inserted if verbosity <= 
                                // the configured verbosity level
                                // E.g., configured: 3 inserts m1, m2 and m3
        Msg(std::ostream &out);

        static void setVerbosity(size_t verbosity);
};
        
extern Msg m1;
extern Msg m2;
extern Msg m3;
extern Msg m4;
extern Msg m5;
extern Msg mp;

#endif
