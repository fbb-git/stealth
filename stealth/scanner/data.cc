#include "scanner.ih"

                // match the last word on lines
Pattern Scanner::s_split("(\\S+)\\s*$");

                // split the first word from the trailing word(s)
Pattern Scanner::s_firstWord("(\\S+)(\\s+(.*))?");

                // pick up the exit value in testExitValue()
Pattern Scanner::s_exitValue("(\\d+)\\s*$");
