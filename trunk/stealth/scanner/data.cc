#include "scanner.ih"

Pattern Scanner::s_split("(\\S+)\\s*$");
Pattern Scanner::s_firstWord("(\\S+)(\\s+(.*))?");
