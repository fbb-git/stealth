#include "pattern.h2"

namespace FBB
{

Pattern::Position Pattern::position(unsigned index) const
{
    regoff_t
        begin;

    return
        (
            !matched || 
            index >= beyondLast || 
            (begin = subExpression[index].rm_so) == -1
        ) ?
            Position(string::npos, string::npos)
        :
            Position(begin, subExpression[index].rm_eo);
}


}
