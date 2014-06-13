#include "runmode.ih"

void RunMode::setMode(Mode mode)
{
    switch ((d_mode = mode))
    {
        default:
        break;

        case LEAVE:
            Lock::unlinkRunFile();  // remove the run file
        break;
    }
}
        
