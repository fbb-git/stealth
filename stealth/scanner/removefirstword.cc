#include "scanner.h2"

bool Scanner::removeFirstWord(char const *word)
{
    if (d_firstWord[1] != word)
        return false;

    d_firstWord.match(d_firstWord[3]);  // make sure firstword[1] now contains
                                        // the next word (of d_firstword[3])
    return true;
}
