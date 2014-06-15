#include "msg.ih"

Msg::Msg()
:
    ostream(imsg.rdbuf())
{}
