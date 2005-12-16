#ifndef _INCLUDED_ERRNO_H_
#define _INCLUDED_ERRNO_H_

#include <string>

namespace FBB
{
    class Errno
    {
        int d_errno;
        std::string d_msg;

        public:
            Errno();
            Errno(char const *prefix);
            Errno(int errnr, char const *text);
            
            int what() const
            {
                return d_errno;
            }
    
            std::string const &why() const
            {
                return d_msg;
            }
    };
}

#endif


