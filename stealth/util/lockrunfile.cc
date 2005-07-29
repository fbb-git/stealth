#include "util.h2"

// In time: make a CFIle object allowing us to open a file, determine its
// file descriptor, and have it closed by its destructor. 

bool Util::lockRunFile(LockType type)
try
{
    if (s_runFILE)
        exit(1, "Internal error: runfile already locked");

    dout("locking " << s_runFilename);

    if (s_runFilename.empty())          // no runfilename, no lock.
        return true;

    dout("open to read " << s_runFilename);

    s_runFILE = fopen(s_runFilename.c_str(), "r");

    if (s_runFILE == 0)
        exit(1, "Can't open run-file `%s'", s_runFilename.c_str());

    if (type == BLOCKING)
    {
        dout("attempting blocking mode lock");
        if (flock(fileno(s_runFILE), LOCK_EX) == 0)
            throw true;
        dout("blocking mode lock FAILED");
    }
    else
    {
        dout("attempting non-blocking mode lock on FD " << fileno(s_runFILE));
        for (unsigned idx = 0; idx < s_maxBlockAttempts; ++idx)
        {
            if (flock(fileno(s_runFILE), LOCK_EX | LOCK_NB) == 0)
                throw true;
            dot();                  // see debugmacro
            ::sleep(1);
            dout("\nNon-blocking mode lock FAILED");
        }
    }
    throw false;
}
catch (bool ret)
{
    dout("locked (and return): " << ret);

    if (!ret)
        exit(1, "Failed to lock run-file `%s'", s_runFilename.c_str());

    return true;
}
