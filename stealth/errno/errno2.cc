/*
                              errno.cc

   $Id$

   $Log$
   Revision 1.2  2003/06/20 18:58:14  frank
   Changes are recorded in stealth/debian/changelog

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
