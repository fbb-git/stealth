#include "pattern.h2"

namespace FBB
{

void Pattern::init(char const *pat, bool caseSensitive, unsigned nSub)
{
    subExpression = new regmatch_t[nSub];
    this->nSub = nSub;
    beyondLast = 0;
    
    string
        pattern(pat);

    for (unsigned idx = 0; idx < sizeofPatmod; ++idx)
        modify(pattern, idx);

    compiled = 
        (
            regcomp
            (
                &regex, pattern.c_str(), REG_EXTENDED | REG_NEWLINE | 
                                (caseSensitive ? 0: REG_ICASE)
            )
            == 0
        );
}

}
