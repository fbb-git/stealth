#ifndef _INCLUDED_IOFORK_H_
#define _INCLUDED_IOFORK_H_


#include "../fork/fork.h"
#include "../pipe/pipe.h"
#include "../ifdnbuf/ifdnbuf.h"
#include "../fdout/fdout.h"
#include <vector>
#include <istream>
#include <ostream>


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

            static void handleTerminatedChild(int);

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









