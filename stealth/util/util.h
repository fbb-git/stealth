#ifndef _INCLUDED_UTIL_H_
#define _INCLUDED_UTIL_H_

#include <iosfwd>

class Util
{
    public:
        static bool mkdir(std::string const &path); // pathname to a file
                                                    // find full path name
        static std::string realPath(std::string const &path);   
        static void absPath(std::string const &path, std::string &fileName);
};
    
#endif

