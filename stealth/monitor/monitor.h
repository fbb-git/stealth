#ifndef _INCLUDED_MONITOR_H_
#define _INCLUDED_MONITOR_H_

#include <iosfwd>
#include <string>
#include <memory>

namespace FBB
{
    class Selector;
    class Arg;
}

class ConfigSorter;
class Reporter;
class Scanner;

class Monitor
{
        // Update s_modeID in data.cc if the following enum changes:
    enum Mode
    {
                        // These numbers are here for debug output referential
                        // purpose only. Their values are not otherwise used
        ONCE,           // 0 single run 
        KEEP_ALIVE,     // 1 multiple runs
        TERMINATE,      // 2 through SIGTERM
        TERMINATED,     // 3 automatically following TERMINATE
        SUPPRESS,       // 4 through SIGUSR1 (SIGUSR2: back to normal)
        SUPPRESSED,     // 5 automatically following SUPPRESS
        RELOAD,         // 6 reload the config files, through SIGPIPE
    };

    static char const *const s_modeID[];
    static Mode             s_mode;
    static bool             s_quit; // passed to Scanner::run() for
                                    // inspection         

    FBB::Arg &d_arg;

    std::string d_sorterPath;
    std::unique_ptr<ConfigSorter> d_sorter;
    std::unique_ptr<Reporter>     d_reporter;
    std::unique_ptr<Scanner>      d_scanner;

    static bool s_keepAlive;

                    // recompile processcontroloptions.cc after changing
                    // the next size_t const value:
    static size_t const s_shortestRepeatInterval = 60;

    static size_t           s_repeatInterval;
    static std::string      s_runFilename;    
    static FBB::Selector    s_selector;
    static size_t           s_delayInterval;    // for the random delay
    static bool             s_mainProcess;

    public:
        Monitor();
        ~Monitor();

        void control();             // control the scanning process
        void mailReport();          // mail the report to the responsible
                                    // person

        static void handleProcessSignals(int signum);

    private:
        void reload();              // reload the configuration files.
        void processMode();         // process the current mode
        void processControlOptions();  // determine the running mode
        void contactOtherStealth();
        void startStealth();
        void handleKeepAliveOption();
        void handleRepeatOption();

        static void setDelay();     // set delay interval matching the
                                    // current mode.

        static void maybeBackground();
        
        static void signalStealth(int signum, char const *signame, 
                                  std::string const &filename);

        static size_t getPid(std::string const &runFile);
        static void randomDelay();

        static void setAlarm();

        static void sleep();               // sleep until wakeup
        static void wait();
        static void wakeup();
        static bool keepAlive();
        static void sendSignal(int sig, char const *signame, pid_t pid);
        static int suppressorPid();
        static void handleReplySignal(int signum);
        static void lock(std::string const &runfile);
};

#endif
