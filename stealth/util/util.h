#ifndef _INCLUDED_UTIL_H_
#define _INCLUDED_UTIL_H_

#ifndef _SYSINC_IOSFWD_
#include <iosfwd>
#define _SYSINC_IOSFWD_
#endif

#ifndef _SYSINC_STRING_
#include <string>
#define _SYSINC_STRING_
#endif


namespace FBB
{
    class Util
    {
        public:
            static std::string fileName(std::string const &name);
            static void exit(int exitvalue, char const *fmt, ...);
            static std::ostream &date(std::ostream &str);
            static std::string datetime();
            static bool isDirectory(std::string const &name);
            static bool mkdir(std::string const &path);  // pathname to a file
            static void randomDelay();
            static void replace(std::string &str, char const *org,
                                             char const *replacement);
            static char const *getVersion();
            static void showVersion();
            static void usage();
            
        private:
            static char version[];
            static char year[];
    };
}
    

#endif
