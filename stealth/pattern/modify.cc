#include "pattern.h2"

namespace FBB
{

void Pattern::modify(string &pattern, unsigned idx)
{
    string::size_type
        pos = 0;

    while (true)
    {
        pos = pattern.find(patmod[idx].first, pos);
        if (pos == string::npos)
            return;
        pattern.replace(pos, strlen(patmod[idx].first), patmod[idx].second);
    }
}

}
