#include "pattern.h2"

namespace FBB
{

string Pattern::beyond() const
{
    unsigned
        begin = subExpression[0].rm_eo;

    return
        matched  && begin < text.length() ?
            text.substr(begin)
        :
            "";
}

}


