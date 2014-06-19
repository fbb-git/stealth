#ifndef INCLUDED_IPC_
#define INCLUDED_IPC_

#include <iosfwd>

#include <bobcat/selector>
#include <bobcat/linearmap>
//#include <bobcat/signal>

class IPC   // : public FBB::SignalHandler
{
    FBB::Selector    d_selector;

    static FBB::LinearMap<int, char const *> const s_signame;

    public:
                                            // always returns true, or
        bool signalPeer(int signum);        // throws exception on failure

        void wait();                        // wait until signaled
        void timedWait();                   // wait until signaled or wait
                                            // until time has passed

        void writeRunFile(pid_t pid);
        void lockRunFile() const;

    private:
        void sleep();                       // sleep until wakeup

        size_t getPid() const;
        static void sendSignal(int sig, pid_t pid);
};

#endif
