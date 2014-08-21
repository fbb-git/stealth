#include "runmode.ih"

void RunMode::setMode(Mode mode)
{
    if ((d_mode = mode) == LEAVE)
        unlink(Options::instance().runFile().c_str());
}
        
