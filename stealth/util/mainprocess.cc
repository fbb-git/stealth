#include "util.h2"

bool Util::mainProcess()
{
    if (s_mainProcess)
        unlinkRunfile();
    return s_mainProcess;
}
