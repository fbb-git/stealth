#ifndef _INCLUDED_ERRNO_H_
#define _INCLUDED_ERRNO_H_

/*
   $Id$

   $Log$
   Revision 1.2  2003/06/20 18:58:14  frank
   Changes are recorded in stealth/debian/changelog

*/


#ifndef _SYSINC_STRING_
#include <string>
#define _SYSINC_STRING_
#endif

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


