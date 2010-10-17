#ifndef INCLUDED_LOCK_
#define INCLUDED_LOCK_

#include <iosfwd>
#include <string>
#include <unistd.h>

class Lock
{
    static FILE        *s_runFILE;             // pointer used for locking
    static std::string  s_runFilename;

    static size_t const s_maxBlockAttempts = 10; // # seconds & tries
                                        // recompile lockrunfile.cc when
                                        // modifying this value
    public:
        enum LockType
        {
            NONBLOCKING,
            BLOCKING,
        };

        static void unlockRunFile();
        static bool lockRunFile(LockType type);
        static void unlinkRunFile();
        static void setRunFilename(std::string const &newName);

        static std::string const &runFilename();

};

inline void Lock::setRunFilename(std::string const &newName)
{
    s_runFilename = newName;
}

inline std::string const &Lock::runFilename()
{
    return s_runFilename;
}

inline void Lock::unlinkRunFile()
{
    unlink(s_runFilename.c_str());  // s_runFilename may be empty 
}

#endif








