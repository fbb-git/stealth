#include "pattern.h2"

namespace FBB
{

string Pattern::before() const
{
    return
        matched ?
            text.substr(0, subExpression[0].rm_so)
        :
            "";
}

}
