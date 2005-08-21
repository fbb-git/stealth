#ifndef _INCLUDED_UTIL_H_
#define _INCLUDED_UTIL_H_

#include <iosfwd>
#include <string>
#include <sys/types.h>
#include <bobcat/selector>

namespace FBB
{
    class Util
    {
        static unsigned const s_maxBlockAttempts = 10; // # seconds & tries
                                            // recompile lockrunfile.cc when
                                            // modifying this value

                        // recompile processcontroloptions.cc after changing
                        // the next unsigned const value:
        static unsigned const s_shortestRepeatInterval = 60;

        static FILE *s_runFILE;             // pointer used for locking
        static Selector s_selector;
        static bool s_keepAlive;
        static bool s_mainProcess;
        static char version[];
        static char year[];
        static std::string s_runFilename;    
        static unsigned s_delayInterval;    // for the random delay
        static unsigned s_repeatInterval;
        static bool s_debug;
    
        public:
            enum Terminate
            {
                OK = 0,
                ERROR = 1,
            };
            enum LockType
            {
                NONBLOCKING,
                BLOCKING,
            };

            static bool debug()
            {
                return s_debug;
            }
            static std::string fileName(std::string const &name);
                                            // exit() itself includes `endl'
            static void handleReplySignal(int signum);
            static bool isDirectory(std::string const &name);
            static bool keepAlive();
            static void sendSignal(int sig, char const *signame, pid_t pid);
            static bool mkdir(std::string const &path);  // pathname to a file
            static std::ostream &date(std::ostream &str);
            static std::string datetime();
            static unsigned getPid(std::string const &runFilename);
            static void exit(int exitvalue, char const *fmt, ...); 

            static bool lockRunFile(LockType lockType);

            static bool mainProcess();
            static void maybeBackground();
            static void processControlOptions();  
            static void randomDelay();
            static void setAlarm();
            static void setDebug(bool value)
            {
                s_debug = value;
            }

            static void sleep();            // sleep until wakeup

            static int suppressorPid();
            static void replace(std::string &str, char const *org,
                                             char const *replacement);
            static void signalStealth(int signum, char const *signame, 
                                     std::string const &filename);
            static void unlockRunFile();

            static char const *getVersion();

            static void showVersion();
            static void unlinkRunfile();
            static void usage();
            static void wait();
            static void wakeup();

        private:
            static void lock(std::string const &runfile);

    };
}
    

#endif
