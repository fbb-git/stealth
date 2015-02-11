#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

#include <iosfwd>
#include <string>
#include <memory>
#include <thread>

#include <bobcat/fork>
#include <bobcat/semaphore>

#include "../runmode/runmode.h"     // includes LinearMap, StealthEnums

//#include "../stealthreport/stealthreport.h"

class PolicyFile;
class IntegrityScanner;
class Options;

//class FatalBuffer;

class Stealth: public StealthEnums, public FBB::Fork
{
    friend class FatalBuffer;

    Options &d_options;

    RunMode d_task;                 // the current run-mode.
    RunMode d_pending;              // a pending run-mode.

    FBB::Semaphore d_ipc;           // Folowing wait Stealth is available
                                    // for the next ipc-command

    FBB::Semaphore d_job;           // Semaphore for the next command
                                    
    bool d_autoJob = false;

//    StealthReport  d_stealthReport;
//    std::ostream d_fatal;


    std::unique_ptr<PolicyFile>         d_policyFile;
    std::unique_pre<IntegrityScanner>   d_integrityScanner;

    typedef std::string (Stealth::*Action)();
    typedef void (Stealth::*Task)();

    static FBB::LinearMap<Mode, Task> s_task;
    static FBB::LinearMap<Mode, Action> s_request;

    public:
        Stealth(Options &options);
        ~Stealth() override;

        bool ipcMode();             // contact a stealth daemon
        void policyMode();       // do all policy-file related tasks

    private:
        void parentProcess() override;  // no actions here
        void childProcess() override;

//        void openStealthReport();

        std::string rerunRequest();
        std::string suspendRequest();
        std::string resumeRequest();
        std::string reloadRequest();
        std::string terminateRequest();
        std::string unknownRequest();
            std::string acceptMode(Mode mode);
            std::string deniedMode(char const *request);

//        void logMsg(char const *label);

//        void mailLogs();        // mail the logs or write them to cout
//            void processMail();
//                void sendMail();

        void doTasks();            // run all scanning (related) tasks 
//            void policyDepDataMembers();

            void jobsHandler();
                void nextJob();
                void reload();          // reload the configuration files.
                void terminate();
                void suspend();
                void resume();
                void rerun();
                void integrityScan();

        void autoScan(char const *label);

        void ipcInterface();            // thread
            bool incomingRequest(std::istream &in, std::ostream &out);
            void notifyTask();

        void waitForKey();              // thread

        static void startThread(void (Stealth::*member)(), Stealth *obj);
};

inline void Stealth::startThread(void (Stealth::*member)(), Stealth *obj)
{
    (obj->*member)();
}

#endif
