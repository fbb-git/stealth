#include "msg.ih"

Msg::Msg(ostream &out)
:
    ostream(out.rdbuf())
{}
