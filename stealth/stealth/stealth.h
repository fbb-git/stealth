#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

#include <string>
#include <memory>
#include <thread>

#include <bobcat/fork>
#include <bobcat/semaphore>


#include "../runmode/runmode.h"     // declares LinearMap

#include "../stealthlog/stealthlog.h"

class PolicyFile;
class IntegrityScanner;
class Options;

class Stealth: public StealthEnums, public FBB::Fork
{
    Options &d_options;
    RunMode d_task;                  // the current run-mode.

    FBB::Semaphore d_command;       // Semaphore for the next command
                                    
    FBB::Semaphore d_remote;        // Semaphore for answering the client
    std::string d_result;           // answer to the client

    std::thread d_scanThread;       // the thread running the scanning process
    bool        d_integrityScan;    // stops the scanning process when false.


    StealthLog     d_stealthLog;
    std::shared_ptr<PolicyFile>         d_policyFile;
    std::shared_ptr<IntegrityScanner>   d_integrityScanner;

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
                void nextMode();

                    void reload();          // reload the configuration files.
                    void terminate();
                    void suspend();
                    void resume();
                    void rerun();
                    void integrityScan();

                    void startScan();
                    void endScanner();

        template <void (Stealth::*fun)()>
        static void startThread(Stealth *obj);
        
            void communicator();
};


template <void (Stealth::*fun)()>
inline void Stealth::startThread(Stealth *obj)
{
    (obj->*fun)();
}

#endif
