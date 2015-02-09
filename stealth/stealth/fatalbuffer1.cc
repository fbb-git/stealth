#include "stealth.ih"

FatalBuffer::FatalBuffer(Stealth *obj)
:
    d_stealth(*obj),
    d_msg("[Fatal] ")
{}

