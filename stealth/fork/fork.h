#ifndef _INCLUDED_FORK_H_
#define _INCLUDED_FORK_H_

namespace FBB
{    
    class Fork
    {
        int
            d_pid;

        public:
            virtual ~Fork()
            {}

            void fork();

            int getPid()
            {
                return d_pid;
            }

        protected:

            virtual void childRedirections()    // do child redirections
            {}            
            virtual void childProcess() = 0;    // must be implemented
            

            virtual void parentRedirections()   // do parent redirections
            {}            
            virtual void parentProcess() = 0;   // must be implemented

            int waitForChild();                 // returns the status
    };
}

#endif


