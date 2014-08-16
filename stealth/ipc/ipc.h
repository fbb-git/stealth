#ifndef INCLUDED_IPC_
#define INCLUDED_IPC_

#include <bobcat/selector>
#include <bobcat/linearmap>

class Options;

class IPC
{
    Options &d_options;
    FBB::Selector    d_selector;

//    static FBB::LinearMap<int, char const *> const s_signame;

    public:
        IPC();
                                            // always returns true, or
        bool signalDaemon(char const *request); // throws exception on failure
        StealthEnums::Mode request() const;  

        void wait();                        // wait until signaled
        void timedWait();                   // wait until signaled or wait
                                            // until time has passed
        void writeRunFile(pid_t pid);

        
    private:
        void sleep();                       // sleep until wakeup

        size_t getPid() const;
        void sendSignal(int sig, pid_t pid);
        void write(char const *request) const;

};

#endif

