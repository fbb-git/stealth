#ifndef _INCLUDED_IOFORK_H_
#define _INCLUDED_IOFORK_H_

#include <vector>
#include <istream>
#include <ostream>

#include <bobcat/fork>
#include <bobcat/pipe>

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
            int getPid()            // must be const, after updating bobcat
            {
                return Fork::getPid();
            }

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
                close(d_in.getWriteFd());   
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









