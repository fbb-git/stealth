#ifndef _INCLUDED_STEALTH_H_
#define _INCLUDED_STEALTH_H_

#include <iosfwd>
#include <string>
#include <memory>
#include <thread>

#include <bobcat/fork>
#include <bobcat/semaphore>

#include "../runmode/runmode.h"     // includes LinearMap, StealthEnums
#include "../options/options.h"
#include "../logunit/logunit.h"

class PolicyFile;
class IntegrityScanner;
class Report;

class Stealth: public StealthEnums, public FBB::Fork
{
    Options d_options;
    LogUnit d_logUnit;

    RunMode d_task;                 // the current run-mode.
    RunMode d_pending;              // a pending run-mode.

    FBB::Semaphore d_ipc;           // Folowing wait Stealth is available
                                    // for the next ipc-command

    FBB::Semaphore d_job;           // Semaphore for the next command
                                    
    bool d_autoJob = false;

    std::unique_ptr<PolicyFile>         d_policyFile;
    std::unique_ptr<IntegrityScanner>   d_integrityScanner;
    std::unique_ptr<Report>      d_report;    // and sends mail

    typedef std::string (Stealth::*Action)();
    typedef void (Stealth::*Task)();

    static FBB::LinearMap<Mode, Task> s_task;
    static FBB::LinearMap<Mode, Action> s_request;

    public:
        Stealth();
        ~Stealth() override;

        bool ipcMode();             // contact a stealth daemon
        void policyMode();       // do all policy-file related tasks

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

        void doTasks();             // run all scanning (related) tasks 
        void setUniquePtrs();       // initialize the unique_ptrs

        void timestamp(char const *label);

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

#endif
