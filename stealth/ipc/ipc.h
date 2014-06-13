#ifndef INCLUDED_IPC_
#define INCLUDED_IPC_

#include <iosfwd>

#include <bobcat/selector>
#include <bobcat/linearmap>
#include <bobcat/signal>

class IPC: public FBB::SignalHandler
{
    FBB::Selector    d_selector;

    static FBB::LinearMap<int, char const *> const s_signame;

    public:
        ~IPC() override;
                                            // always returns true, or
                                            // throws exception on failure
        bool signalPeer(int signum);
        void wakeup();
        void setAlarm();
        void wait();                        // wait until signalled
        void sleep();                       // sleep until wakeup
        void sleep(size_t seconds);         // sleep until wakeup

        bool signalSuppressor();            // stealth daemon signals the 
                                            // stealth process that issued
                                            // --suppress

        void writeRunFile(pid_t pid);
        void lockRunFile() const;

    private:
        void signalHandler(size_t signum) override;

        void suppress(size_t pid);
        void suppressing(size_t pid);

        size_t getPid() const;

        static void sendSignal(int sig, pid_t pid);

};

inline void IPC::wakeup() 
{
    d_selector.setAlarm(0);
}

#endif
