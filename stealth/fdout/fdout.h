#ifndef _INCLUDED_FDOUT_H_
#define _INCLUDED_FDOUT_H_

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
    class ofdnstreambuf: public std::streambuf
    {
        unsigned d_bufsize;
        int     d_fd;
        char    *d_buffer;

        public:
            ofdnstreambuf()
            :
                d_bufsize(0),
                d_buffer(0)
            {}
    
            ofdnstreambuf(int fd, unsigned bufsize = 1)
            {
                open(fd, bufsize);
            }
    
            ~ofdnstreambuf()
            {
                if (d_buffer)
                {
                    sync();                                     // 1
                    delete d_buffer;
                }
            }
    
            void open(int fd, unsigned bufsize = 1)
            {
                d_fd = fd;
                d_bufsize = bufsize == 0 ? 1 : bufsize;
            
                d_buffer = new char[d_bufsize];
                setp(d_buffer, d_buffer + d_bufsize);           // 2
            }
    
            int sync()
            {
                if (pptr() > pbase())
                {
                    write(d_fd, d_buffer, pptr() - pbase());    // 3
                    setp(d_buffer, d_buffer + d_bufsize);       // 4
                }
                return 0;
            }
    
            int overflow(int c)
            {
                sync();                                         // 5
                if (c != EOF)
                {
                    *pptr() = static_cast<char>(c);             // 6
                    pbump(1);
                }
                return c;
            }
    };
}

#endif
