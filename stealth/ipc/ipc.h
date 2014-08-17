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
    bool            d_timeout = false;

    static FBB::LinearMap<std::string, Mode> const s_request;

    public:
        IPC();
                                            // always returns true, or
        bool signalDaemon(char const *request); // throws exception on failure
        StealthEnums::Mode request();  
        std::string const &requestText() const;

        void wait();                        // wait until signaled

        void timedWait();                   // wait until signaled or wait
                                            // until time has passed
        bool timeout() const;               // true if timedWait's waiting
                                            // time has expired

        void writeRunFile(pid_t pid);

        
    private:
        void sleep();                       // sleep until wakeup

        size_t getPid() const;
        void sendSignal(int sig, pid_t pid);
        void write(char const *request) const;

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

