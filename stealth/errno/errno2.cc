/*
                              errno.cc

   $Id$

   $Log$
   Revision 1.1  2003/06/20 18:38:28  frank
   Initial revision

*/

#include "errno.ih"

Errno::Errno(char const *prefix)
:
    d_errno(errno),
    d_msg(prefix ? prefix : "")
{
    if (d_msg.length())
        (d_msg  += ": ") += strerror(d_errno);
}
