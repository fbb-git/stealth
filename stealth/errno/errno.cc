/*
                              errno.cc

   $Id$

   $Log$
   Revision 1.2  2003/06/20 18:58:14  frank
   Changes are recorded in stealth/debian/changelog

*/

#include "errno.ih"

Errno::Errno()
:
    d_errno(errno),
    d_msg(strerror(d_errno))
{}
