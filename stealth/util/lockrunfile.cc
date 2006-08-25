#include "util.ih"

// In time: make a CFIle object allowing us to open a file, determine its
// file descriptor, and have it closed by its destructor. 

bool Util::lockRunFile(LockType type)
try
{
    if (s_runFILE)
        exit("Internal error: runfile already locked");

    debug() << "locking " << s_runFilename << endl;

    if (s_runFilename.empty())          // no runfilename, no lock.
        return true;

    debug() << "open to read " << s_runFilename << endl;

    s_runFILE = fopen(s_runFilename.c_str(), "r");

    if (s_runFILE == 0)
        exit("Can't open run-file `%s'", s_runFilename.c_str());

    if (type == BLOCKING)
    {
        debug() << "attempting blocking mode lock" << endl;
        if (flock(fileno(s_runFILE), LOCK_EX) == 0)
            throw true;
        debug() << "blocking mode lock FAILED" << endl;
    }
    else
    {
        debug() << "attempting non-blocking mode lock on FD " << 
                                                    fileno(s_runFILE) << endl;
        for (size_t idx = 0; idx < s_maxBlockAttempts; ++idx)
        {
            if (flock(fileno(s_runFILE), LOCK_EX  | LOCK_NB) == 0)
                throw true;
            debug() << "." << flush;
            ::sleep(1);
            debug() << "\nNon-blocking mode lock FAILED" << endl;
        }
    }
    throw false;
}
catch (bool ret)
{
    debug() << "locked (and return): " << ret << endl;

    if (!ret)
        exit("Failed to lock run-file `%s'", s_runFilename.c_str());

    return true;
}
