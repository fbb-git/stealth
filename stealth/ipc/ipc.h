#ifndef INCLUDED_IPC_
#define INCLUDED_IPC_

#include <string>

#include <bobcat/selector>
#include <bobcat/linearmap>

#include "../stealthenums/stealthenums.h"

class Options;

class IPC: public StealthEnums
{
    Options        &d_options;
    FBB::Selector   d_selector;
    std::string     d_requestText;
    size_t          d_requestorPid;
    bool            d_timeout = false;

    static FBB::LinearMap<std::string, Mode> const s_request;

    public:
        IPC();
                                            // always returns true, or
        bool signalDaemon();                // throws exception on failure

        StealthEnums::Mode request();       // retrieve the request/msg and 
                                            // requestor's pid
        std::string const &requestText() const;

        void sendRequestor(std::string const &msg);

        void wait(bool doM2 = true);        // wait until signaled
        
        void timedWait();                   // wait until signaled or wait
                                            // until time has passed
        bool timeout() const;               // true if timedWait's waiting
                                            // time has expired

        void writeRunFile(pid_t pid);

        void write(std::string const &msg) const;   // write msg and own pid
                                                    // to the runfile
        
    private:
        void sleep();                       // sleep until wakeup

        size_t daemonPid() const;
        void sendRequest(char const *request, pid_t pid);
};

inline bool IPC::timeout() const
{
    return d_timeout;
}

inline std::string const &IPC::requestText() const
{
    return d_requestText;
}

#endif

