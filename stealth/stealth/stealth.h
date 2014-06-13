#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

// #include <iosfwd>
#include <string>
#include <memory>

#include <bobcat/signal>
#include <bobcat/fork>

#include "../runmode/runmode.h"     // declares LinearMap
#include "../ipc/ipc.h"

class PolicyFile;
class Reporter;
class IntegrityScanner;
class Options;

class Stealth: public ModeEnum, public FBB::Fork, public FBB::SignalHandler
{
    Options &d_options;
    IPC d_ipc;

    RunMode d_run;

    std::unique_ptr<PolicyFile>       d_policyFile;
    std::unique_ptr<Reporter>           d_reporter;
    std::unique_ptr<IntegrityScanner>   d_integrityScanner;

    bool d_keepAlive;

    typedef void (Stealth::*Action)();

    static FBB::LinearMap<Mode, Action> s_task;
    static FBB::LinearMap<size_t,  Action> s_signalHandler;

    public:
        Stealth();
        ~Stealth() override;

        bool contactPeer();         // contact a stealth daemon
        void processPolicy();       // do all policy-file related tasks

    private:
        void childProcess() override;
        void parentProcess() override;
        void signalHandler(size_t signum) override;
            void rerunSignal();
            void suspendSignal();
            void resumeSignal();
            void reloadSignal();
            void terminateSignal();

        void report(char const *label);

        void doChores();            // run all scanning (related) tasks 
            void allocateUniquePtrs();
            void setupSignals();
            void integrityScan();
            void reload();          // reload the configuration files.
            void terminate();
            void suspend();
            void mailReport();      // mail the report to the responsible
                                    // person
};

#endif








