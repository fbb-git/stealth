#include "runmode.ih"

void RunMode::setMode(Mode mode)
{
    switch ((d_mode = mode))
    {
        default:
        break;

        case LEAVE:
//            Lock::unlockRunFile();  // unlock the run file
//            Lock::unlinkRunFile();  // remove the run file
            unlink(Options::instance().runFile().c_str());
        break;
    }
}
        
