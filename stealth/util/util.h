#ifndef _INCLUDED_UTIL_H_
#define _INCLUDED_UTIL_H_

#include <iosfwd>
#include <string>
#include "../selector/selector.h"

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
            static bool isDirectory(std::string const &name);
            static bool keepAlive();
            static bool mkdir(std::string const &path);  // pathname to a file
            static std::ostream &date(std::ostream &str);
            static std::string datetime();
            static unsigned getPid(std::string const &runFilename);
            static void exit(int exitvalue, char const *fmt, ...); 
// OBSOLETE            static void handleRerun(int);
// OBSOLETE            static void handleSIGUSR1(int);
// OBSOLETE            static void handleTerminate(int);

// NEW
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

// NEW
            static void sleep();            // sleep until wakeup

            static void replace(std::string &str, char const *org,
                                             char const *replacement);
// NEW
            static void signalStealth(int signum, char const *signame, 
                                     std::string const &filename);
// NEW
            static void unlockRunFile();

            static char const *getVersion();

            static void showVersion();
            static void unlinkRunfile();
            static void usage();
            static void wait();
// NEW
            static void wakeup();

        private:
// NEW
            static void lock(std::string const &runfile);

    };
}
    

#endif
