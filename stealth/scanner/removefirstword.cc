#include "scanner.h2"

bool Scanner::removeFirstWord(char const *word)
{
    if (d_firstWord[1] != word)
        return false;

    d_firstWord.match(d_firstWord[2]);
    return true;
}
