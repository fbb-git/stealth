#include "util.ih"

bool Util::mainProcess()
{
    if (s_mainProcess)
        unlinkRunfile();
    return s_mainProcess;
}
