#include "pattern.h2"

namespace FBB
{

bool Pattern::match(char const *text)
{
    this->text = text;

    matched = 
            !compiled ?
                false
            :
                regexec(&regex, text, nSub, subExpression, 0) == 0;

    if (matched)
    {
        for (beyondLast = nSub; beyondLast--; )
        {
            if (subExpression[beyondLast].rm_so != -1)
            {
                ++beyondLast;
                break;
            }            
        }
    }
    else
        beyondLast = 0;

    return matched;
}


}
