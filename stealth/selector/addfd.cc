/*
                              selector.cc

   $Id$

   $Log$
   Revision 1.1  2003/11/27 15:03:12  frank
   Added facilities for keeping the ssh connection: --keep-alive, --repeat,
       --terminate and --rerun

   Revision 1.1.1.1  2003/05/31 13:19:21  frank
   Initial import of Selector

   Revision 1.1.1.1  2003/05/31 12:44:34  frank
   Initial import of Selector

*/

#include "selector.ih"

using namespace std;
using namespace FBB;


void Selector::addFd(fd_set *set, int fd)
{
    FD_SET(fd, set);
    if (fd >= d_max)
        d_max = fd + 1;
}

