/*
                              errno.cc

   $Id$

   $Log$
   Revision 1.1  2003/06/20 18:38:28  frank
   Initial revision

*/

#include "errno.ih"

Errno::Errno(int err, char const *text)
:
    d_errno(err),
    d_msg(text ? text : "")
{}
