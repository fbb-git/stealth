#include "integrityscanner.ih"

bool IntegrityScanner::removeFirstWord(char const *word)
{
    if (s_firstWord[1] != word)
        return false;

    s_firstWord.match(s_firstWord[3]);  // make sure firstword[1] now contains
                                        // the next word (of d_firstword[3])
    return true;
}
