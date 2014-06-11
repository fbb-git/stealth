#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

// #include <iosfwd>
#include <string>
#include <memory>

#include <bobcat/signal>
#include <bobcat/fork>

#include "../runmode/runmode.h"
#include "../ipc/ipc.h"

class PolicyFile;
class Reporter;
class IntegrityScanner;
class Options;

class Stealth: public RunMode, public FBB::Fork, public FBB::SignalHandler
{
    bool             d_quit = false;    // passed to IntegrityScanner::run() 
                                        // for inspection         

    Options &d_options;
    IPC d_ipc;

    std::unique_ptr<PolicyFile>       d_policyFile;
    std::unique_ptr<Reporter>           d_reporter;
    std::unique_ptr<IntegrityScanner>   d_integrityScanner;

    bool d_keepAlive;

//    static size_t                       d_repeatInterval;
//    static std::string      s_runFilename;    
    //static size_t           d_delayInterval;    // for the random delay
//    static bool             s_mainProcess;

    public:
        Stealth();
        ~Stealth() override;

        bool contactPeer();         // contact another stealth process
        void run();                 // run the scanning process
        void mailReport();          // mail the report to the responsible
                                    // person

//        static void handleProcessSignals(int signum);
//
    private:
        void childProcess() override;
        void parentProcess() override;
        void signalHandler(size_t signum) override;

        void report(char const *label);

        void reload();              // reload the configuration files.
        void processMode();         // process the current mode

        void startup();
        void handleKeepAliveOption();

        void integrityScan();

        void setDelay();            // set delay interval matching the
                                    // current mode.

//        static void setAlarm();
//
//        static void sleep();               // sleep until wakeup
//        static void wait();
//        static void wakeup();
//        static bool keepAlive();
//        static void sendSignal(int sig, char const *signame, pid_t pid);

        static int suppressorPid();

//        static void handleReplySignal(int signum);
//        static void lock(std::string const &runfile);
};

#endif








