#ifndef _INCLUDED_PARENTSLURP_H_
#define _INCLUDED_PARENTSLURP_H_


    #include "../../../fork/fork.h"
    #include "../../../pipe/pipe.h"
    #include "../../../ifdnbuf/ifdnbuf.h"
    #include "../../../fdout/fdout.h"

    #include <unistd.h>

#ifndef _SYSINC_ISTREAM_
#include <istream>
#define _SYSINC_ISTREAM_
#endif

    #ifndef _SYSINC_IOSTREAM_
#include <iostream>
#define _SYSINC_IOSTREAM_
#endif

namespace FBB
{
    class IOFork: public Fork
    {
        std::string d_cmd;

        Pipe    d_out;
        Pipe    d_in;

        std::istream *d_ins;        // for the parent: read
        std::ostream *d_outs;        // for the parent: read

        public:
            static void handleTerminatedChild(int signal);

            IOFork(std::string const &cmd)
            :
                d_cmd(cmd)
            {}

            ~IOFork();

            std::istream &in()
            {
                return *d_ins;
            }

            std::ostream &out()
            {
                return *d_outs;
            }

        protected:
            virtual void childRedirections();
            virtual void parentRedirections();

            virtual void childProcess();
            virtual void parentProcess() 
            {}

        private:
            char const **split(std::vector<std::string> &vs);
    };

}


#endif

#ifndef _SYSINC_IOSTREAM_
#include <iostream>
#define _SYSINC_IOSTREAM_
#endif

#ifndef _SYSINC_SYS_TYPES_H_
#include <sys/types.h>
#define _SYSINC_SYS_TYPES_H_
#endif

#ifndef _SYSINC_SIGNAL_H_
#include <signal.h>
#define _SYSINC_SIGNAL_H_
#endif

#ifndef _INCLUDED_PATTERN_H_
#include "../pattern/pattern.h"
#endif

#ifndef _SYSINC_SYS_TYPES_H_
#include <sys/types.h>
#define _SYSINC_SYS_TYPES_H_
#endif

#ifndef _SYSINC_SYS_STAT_H_
#include <sys/stat.h>
#define _SYSINC_SYS_STAT_H_
#endif

#ifndef _SYSINC_FCNTL_H_
#include <fcntl.h>
#define _SYSINC_FCNTL_H_
#endif

#ifndef _INCLUDED_UTIL_H_
#include "../util/util.h"
#endif

using namespace std;
using namespace FBB;


