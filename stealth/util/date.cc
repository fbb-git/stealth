#include "util.h2"

ostream & Util::date(std::ostream &str)
{ 
    time_t curtime = time (NULL);

    char *cp = asctime(localtime(&curtime));

    return str.write(cp, strlen(cp) - 1);
}

