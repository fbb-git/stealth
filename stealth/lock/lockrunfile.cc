#include "lock.ih"

// In time: make a CFIle object allowing us to open a file, determine its
// file descriptor, and have it closed by its destructor. 

bool Lock::lockRunFile(LockType type)
try
{
    if (s_runFILE)
        msg() << "Internal error: runfile already locked" << fatal;

    msg() << "locking " << s_runFilename << info;

    if (s_runFilename.empty())          // no runfilename, no lock.
        return true;

    msg() << "open to read " << s_runFilename << info;

    s_runFILE = fopen(s_runFilename.c_str(), "r");

    if (s_runFILE == 0)
        msg() << "Can't open run-file `" << s_runFilename.c_str() << '\'' <<
                                                                        fatal;

    if (type == BLOCKING)
    {
        msg() << "attempting blocking mode lock" << info;
        if (flock(fileno(s_runFILE), LOCK_EX) == 0)
            throw true;
        msg() << "blocking mode lock FAILED" << info;
    }
    else
    {
        msg() << "attempting non-blocking mode lock on FD " << 
                                                    fileno(s_runFILE) << info;
        for (size_t idx = 0; idx < s_maxBlockAttempts; ++idx)
        {
            if (flock(fileno(s_runFILE), LOCK_EX  | LOCK_NB) == 0)
                throw true;
            msg() << "." << spool;
            ::sleep(1);
            msg() << "\nNon-blocking mode lock FAILED" << info;
        }
    }
    throw false;
}
catch (bool ret)
{
    msg() << "locked (and return): " << ret << info;

    if (!ret)
        msg() << "Failed to lock run-file `" << s_runFilename << '\'' << 
                                                                    fatal;
    return true;
}
