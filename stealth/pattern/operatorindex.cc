#include "pattern.h2"

namespace FBB
{

string  Pattern::operator[](unsigned index) const
{
    regoff_t
        begin;

    return
        (
            !matched ||
            index >= beyondLast ||
            (begin = subExpression[index].rm_so) == -1
        ) ?
            ""
        :
            text.substr(begin, subExpression[index].rm_eo - begin);
}


}
