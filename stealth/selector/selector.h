#ifndef _INCLUDED_SELECTOR_H_
#define _INCLUDED_SELECTOR_H_

/*
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

#ifndef _SYSINC_SYS_TIME_H_
#include <sys/time.h>
#define _SYSINC_SYS_TIME_H_
#endif

#ifndef _SYSINC_SYS_TYPES_H_
#include <sys/types.h>
#define _SYSINC_SYS_TYPES_H_
#endif

#ifndef _SYSINC_UNISTD_H_
#include <unistd.h>
#define _SYSINC_UNISTD_H_
#endif

#ifndef _SYSINC_LIMITS_H_
#include <limits.h>
#define _SYSINC_LIMITS_H_
#endif


namespace FBB
{
    class Selector
    {
        fd_set          d_read;
        fd_set          d_write;
        fd_set          d_except;
        fd_set          d_ret_read;
        fd_set          d_ret_write;
        fd_set          d_ret_except;
        timeval         d_alarm;
        int             d_max;
        int             d_ret;
        int             d_readidx;
        int             d_writeidx;
        int             d_exceptidx;

        public:
            Selector();

            int wait();             // nReady() and the get...() members 
                                    // perform defined behavior only after 
                                    // wait() returns.

            int nReady()            // number of available fd's. 0: timeout
            {                       // occurred, -1: select() failed.
                return d_ret;
            }

            int getReadFd()             // -1 if no more available descriptors
            {                           // otherwise the next available fd    
                                        // in each category
                return checkSet(&d_readidx, d_ret_read);
            }

            int getWriteFd()
            {               
                return checkSet(&d_writeidx, d_ret_write);
            }

            int getExceptFd()
            {                
                return checkSet(&d_exceptidx, d_ret_except);
            }

            
            void setAlarm(int sec, int usec = 0)
            {
                d_alarm.tv_sec  = sec;
                d_alarm.tv_usec = usec;
            }

            void noAlarm()
            {
                setAlarm(INT_MAX, INT_MAX);
            }

            void addReadFd(int fd)
            {
                addFd(&d_read, fd);
            }

            void addWriteFd(int fd)
            {
                addFd(&d_write, fd);
            }

            void addExceptFd(int fd)
            {
                addFd(&d_except, fd);
            }

            void rmReadFd(int fd)
            {
                FD_CLR(fd, &d_read);
            }

            void rmWriteFd(int fd)
            {
                FD_CLR(fd, &d_write);
            }

            void rmExceptFd(int fd)
            {
                FD_CLR(fd, &d_except);
            }

        private:
            int checkSet(int *index, fd_set &set);
            void addFd(fd_set *set, int fd);
    };
}

#endif

