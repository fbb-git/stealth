#include "util.h2"

string Util::datetime()
{ 
    time_t curtime = time(0);

    char buffer[80];
    strftime(buffer, 80, "%Y%m%d-%H%M%S", localtime(&curtime));

    return buffer;
}

