#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

#include <string>
#include <memory>

#include <bobcat/fork>
#include "../semaphore/semaphore" 


#include "../runmode/runmode.h"     // declares LinearMap

//#include "../ipc/ipc.h"

#include "../stealthlog/stealthlog.h"

class PolicyFile;
class IntegrityScanner;
class Options;

class Stealth: public StealthEnums, public FBB::Fork
{
    Options &d_options;
    RunMode d_run;

    StealthLog     d_stealthLog;
    std::shared_ptr<PolicyFile>         d_policyFile;
    std::shared_ptr<IntegrityScanner>   d_integrityScanner;

    FBB::Semaphore d_communicate;
    std::string d_result;
    FBB::Semaphore d_chore;
    int d_request;

    typedef std::string (Stealth::*Action)();
    typedef void (Stealth::*Task)();

    static FBB::LinearMap<Mode, Task> s_task;
    static FBB::LinearMap<Mode, Action> s_request;

    public:
        Stealth();
        ~Stealth() override;

        bool contactPeer();         // contact a stealth daemon
        void processPolicy();       // do all policy-file related tasks

    private:
                                    // constructs uds-filename from
                                    // d_use["BASE"] and 
                                    // options.unixDomainSocket()
        std::string unixDomainSocket() const;    

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
                Mode nextTask();
                void process(Mode request); // process one single request
                    void reload();          // reload the configuration files.
                    void terminate();
                    void suspend();
                    void resume();
                    void integrityScan();

        void wait();                // wait for command or timeout. At timeout
                                    // the mode is set to INTEGRITY_SCAN




//                void waitForRequest();

            static void comThread(Stealth *obj);
            void communicator();
};

inline void Stealth::comThread(Stealth *obj)
{
    obj->communicator();
}

#endif
