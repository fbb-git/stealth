#include "util.ih"

void Util::unlockRunFile()
{
    if (s_runFILE)
        fclose(s_runFILE);              // closing removes the lock
    s_runFILE = 0;
}
