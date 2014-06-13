#include "lock.ih"

// In time: make a CFIle object allowing us to open a file, determine its
// file descriptor, and have it closed by its destructor. 

bool Lock::lockRunFile(LockType type)
try
{
//    if (s_runFILE)
//        fmsg << "Internal error: runfile already locked" << endl;
//
//    if (s_runFilename.empty())          // no runfilename, no lock.
//    {
//        imsg << "No need to lock a run file" << endl;
//        return true;
//    }

    imsg << "opening `" << s_runFilename << "' for reading" << endl;

    s_runFILE = fopen(s_runFilename.c_str(), "r");

    if (s_runFILE == 0)
        fmsg << "Can't open run-file `" << s_runFilename.c_str() << '\'' <<
                                                                        endl;

    if (type == BLOCKING)
    {
//        imsg << "attempting blocking mode lock" << endl;
//        if (flock(fileno(s_runFILE), LOCK_EX) == 0)
            throw true;
//        imsg << "blocking mode lock FAILED" << endl;
    }
    else
    {
        imsg << "attempting non-blocking mode lock on FD " << 
                                                    fileno(s_runFILE) << endl;
//        for (size_t idx = 0; idx < s_maxBlockAttempts; ++idx)
//        {
//            if (flock(fileno(s_runFILE), LOCK_EX  | LOCK_NB) == 0)
                throw true;
//            imsg << '.';
//            ::sleep(1);
//            imsg << "\nNon-blocking mode lock FAILED" << endl;
//        }
    }
    throw false;
}
catch (bool ret)
{
    imsg << "locked (and return): " << ret << endl;

//    if (!ret)
//        fmsg << "Failed to lock run-file `" << s_runFilename << '\'' << endl;

    return true;
}



