#ifndef _INCLUDED_UTIL_H_
#define _INCLUDED_UTIL_H_

#include <iosfwd>
#include <string>
#include "../selector/selector.h"

namespace FBB
{
    class Util
    {
        static bool s_keepAlive;
        static unsigned s_repeatInterval;
        static unsigned s_delayInterval;    // for the random delay
        static Selector s_selector;
        static std::string s_runFilename;    
    
        public:
            static std::string fileName(std::string const &name);
                                            // exit() itself includes `endl'
            static void exit(int exitvalue, char const *fmt, ...); 
            static std::ostream &date(std::ostream &str);
            static std::string datetime();
            static unsigned getPid(std::string const &runFilename);
            static void handleSIGUSR1(int signum);
            static void handleRerun(int signum);
            static void handleTerminate(int signum);
            static bool keepAlive();
            static void maybeBackground();
            static void setAlarm();
            static bool isDirectory(std::string const &name);
            static bool mkdir(std::string const &path);  // pathname to a file
            static void processControlOptions();  
            static void randomDelay();
            static void replace(std::string &str, char const *org,
                                             char const *replacement);
            static char const *getVersion();
            static void showVersion();
            static void unlinkRunfile();
            static void usage();
            static void wait();
            
        private:
            static char version[];
            static char year[];
    };
}
    

#endif
