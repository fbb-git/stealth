#include "monitor.ih"

Monitor::~Monitor()
{
    Lock::unlinkRunFile();
}




