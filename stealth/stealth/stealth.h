#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

#include <string>
#include <memory>

#include <bobcat/fork>

#include "../runmode/runmode.h"     // declares LinearMap
#include "../ipc/ipc.h"
#include "../stealthlog/stealthlog.h"
#include "../semaphore/semaphore.h"

class PolicyFile;
class IntegrityScanner;
class Options;

class Stealth: public StealthEnums, public FBB::Fork
{
//    static size_t const s_contactPeerWaitSeconds = 3;

    Options &d_options;
    IPC d_ipc;

    RunMode d_run;
    volatile bool d_request;

    StealthLog     d_stealthLog;
    std::shared_ptr<PolicyFile>         d_policyFile;
    std::shared_ptr<IntegrityScanner>   d_integrityScanner;

    Semaphore d_chore;
    int d_request;
    Semaphore d_communicate;

    typedef std::string (Stealth::*Action)();

    static FBB::LinearMap<Mode, Action> s_task;
    static FBB::LinearMap<Mode, Action> s_request;

    public:
        Stealth();
        ~Stealth() override;

        void contactPeer();         // contact a stealth daemon
        void processPolicy();       // do all policy-file related tasks

    private:
        void parentProcess() override;  // no actions here
        void childProcess() override;

        std::string rerunRequest();
        std::string suspendRequest();
        std::string resumeRequest();
        std::string reloadRequest();
        std::string terminateRequest();
        std::string unknownRequest();
            std::string acceptMode(Mode mode);
            std::string deniedMode(char const *request);

        void logMsg(char const *label);

        void mailLogs();        // mail the logs or write them to cout
            void processMail();
                void sendMail();

        void doChores();            // run all scanning (related) tasks 
            void policyDepDataMembers();

            void processRequests();
                void process(Mode request);     // process one single request
                void waitForRequest();

            void integrityScan();


            void reload();          // reload the configuration files.
            void terminate();
            void suspend();
            void resume();

            static void comThread(Stealth *obj);
            void communicator();
};

inline void Stealth::comThread(Stealth *obj)
{
    obj->communicator();
}

#endif
