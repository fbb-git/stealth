#ifndef _INCLUDED_UTIL_H_
#define _INCLUDED_UTIL_H_

#include <iosfwd>

class Util
{
    public:
        static bool mkdir(std::string const &path); // pathname to a file
                                                    // find full path name
        static std::string fullPath(std::string const &path);   

};
    
#endif

