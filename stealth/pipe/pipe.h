#ifndef _INCLUDED_PIPE_H_
#define _INCLUDED_PIPE_H_

#ifndef _SYSINC_UNISTD_H_
#include <unistd.h>
#define _SYSINC_UNISTD_H_
#endif


namespace FBB
{
    class Pipe
    {
        private:
            enum    RW { READ, WRITE };
            int     d_fd[2];

            void redirect(int d_fd, int alternateFd);
    
        public:
            Pipe();

            void closeWrite()
            {
                close(d_fd[WRITE]);
            }

            int useForReading();
            void useForReadingFrom(int fileDescriptor);   

            int useForWriting();
            void useForWritingTo(int fileDescriptor);
            void useForWritingTo(int const *fileDescriptors, unsigned n = 2);
    };
}

#endif
