#include "selector.ih"

using namespace std;
using namespace FBB;


int Selector::wait()
{
    timeval t = d_alarm;

    d_ret_read = d_read;
    d_ret_write = d_write;
    d_ret_except = d_except;

    d_readidx = 0;
    d_writeidx = 0;
    d_exceptidx = 0;

    return select(d_max, &d_ret_read, &d_ret_write, &d_ret_except, &t);
}

