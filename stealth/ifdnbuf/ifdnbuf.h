#ifndef _INCLUDED_IFDNBUF_H_
#define _INCLUDED_IFDNBUF_H_

#ifndef _SYSINC_UNISTD_H_
#include <unistd.h>
#define _SYSINC_UNISTD_H_
#endif

#ifndef _SYSINC_STREAMBUF_
#include <streambuf>
#define _SYSINC_STREAMBUF_
#endif

#ifndef _SYSINC_IOS_
#include <ios>
#define _SYSINC_IOS_
#endif

namespace FBB
{    
    class ifdnstreambuf: public std::streambuf
    {
        protected:
            int         d_fd;
            unsigned    d_bufsize;
            char*       d_buffer;
        public:
            ifdnstreambuf()
            :
                d_bufsize(0),
                d_buffer(0)
            {}

            ifdnstreambuf(int fd, unsigned bufsize = 1)
            {
                open(fd, bufsize);
            }

            ~ifdnstreambuf()
            {
                if (d_bufsize)
                {
                    close(d_fd);
                    delete d_buffer;                                // 1
                }
            }

            void open(int fd, unsigned bufsize = 1)
            {
                d_fd = fd;
                d_bufsize = bufsize;
                d_buffer = new char[d_bufsize];
                setg(d_buffer, d_buffer + d_bufsize, d_buffer + d_bufsize);
            }
    
            int underflow()
            {
                if (gptr() < egptr())
                    return static_cast<unsigned char>(*gptr());
    
                int nread = read(d_fd, d_buffer, d_bufsize);
    
                if (nread <= 0)
                    return EOF;
        
                setg(d_buffer, d_buffer, d_buffer + nread);         // 2
                return static_cast<unsigned char>(*gptr());
            }
    
            std::streamsize xsgetn(char *dest, std::streamsize n)   // 3
            {
                int nread = 0;
    
                while (n)
                {
                    if (!in_avail())
                    {
                        if (underflow() == EOF)                     // 4
                            break;
                    }
    
                    int avail = in_avail();
    
                    if (avail > n)
                        avail = n;
    
                    memcpy(dest + nread, gptr(), avail);            // 5
                    gbump(avail);                                   // 6
    
                    nread += avail;
                    n -= avail;
                }
    
                return nread;
            }
    };
}

#endif
