#ifndef _INCLUDED_IOFORK_H_
#define _INCLUDED_IOFORK_H_


#ifndef _INCLUDED_FORK_H_
#include "../fork/fork.h"
#endif

#ifndef _INCLUDED_PIPE_H_
#include "../pipe/pipe.h"
#endif

#ifndef _INCLUDED_IFDNBUF_H_
#include "../ifdnbuf/ifdnbuf.h"
#endif

#ifndef _INCLUDED_FDOUT_H_
#include "../fdout/fdout.h"
#endif

#ifndef _SYSINC_VECTOR_
#include <vector>
#define _SYSINC_VECTOR_
#endif

#ifndef _SYSINC_ISTREAM_
#include <istream>
#define _SYSINC_ISTREAM_
#endif

#ifndef _SYSINC_OSTREAM_
#include <ostream>
#define _SYSINC_OSTREAM_
#endif


namespace FBB
{    
    class IOFork: public Fork
    {
        std::string d_cmd;

        Pipe        d_in;           // read by the parent
        Pipe        d_out;          // written by the parent    

        std::istream *d_ins;        // for the parent: read
        std::ostream *d_outs;       // and write

        public:

            static void handleTerminatedChild(int signal);

            std::istream &in()
            {
                return *d_ins;
            }
            
            std::ostream &out()
            {
                return *d_outs;
            }

            IOFork(std::string const &cmd)
            :
                d_cmd(cmd)
            {}

            ~IOFork();

            void waitForChild()
            {
                d_in.closeWrite();
                Fork::waitForChild();
            }
             
        protected:
            virtual void childRedirections();
            virtual void parentRedirections();  

            virtual void childProcess();  
            virtual void parentProcess()    // left to the main program
            {}

        private:
            char const **split(std::vector<std::string> &vs);
    };
}

#endif









