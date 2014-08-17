#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

#include <string>
#include <memory>

#include <bobcat/signal>
#include <bobcat/fork>

#include "../runmode/runmode.h"     // declares LinearMap
#include "../ipc/ipc.h"
#include "../stealthlog/stealthlog.h"

class PolicyFile;
class IntegrityScanner;
class Options;

class Stealth: public StealthEnums, public FBB::Fork, public FBB::SignalHandler
{
    Options &d_options;
    IPC d_ipc;

    RunMode d_run;
    volatile bool d_request;

    StealthLog     d_stealthLog;
    std::unique_ptr<PolicyFile>         d_policyFile;
    std::unique_ptr<IntegrityScanner>   d_integrityScanner;

    typedef void (Stealth::*Action)();

    static FBB::LinearMap<Mode, Action> s_task;
    static FBB::LinearMap<Mode, Action> s_request;

    public:
        Stealth();
        ~Stealth() override;

        bool contactPeer();         // contact a stealth daemon
        void processPolicy();       // do all policy-file related tasks

    private:
        void childProcess() override;
        void parentProcess() override;
        void signalHandler(size_t signum) override;
            void rerunRequest();
            void suspendRequest();
            void resumeRequest();
            void reloadRequest();
            void terminateRequest();

        void logMsg(char const *label);

        void mailLogs();        // mail the logs or write them to cout
            void processMail();
                void sendMail();

        void doChores();            // run all scanning (related) tasks 
            void policyDepDataMembers();
            void setupSignals();

            void processRequests();
                void process(Mode request);     // process one single request
                void waitForRequest();

            void integrityScan();


            void reload();          // reload the configuration files.
            void terminate();
            void suspend();
            void resume();

};

#endif








