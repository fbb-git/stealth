#include "stealth.ih"

int FatalBuffer::overflow(int ch)
{
    if (ch != EOF)
        d_msg += ch;
    return ch;
}
