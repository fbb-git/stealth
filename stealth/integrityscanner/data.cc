#include "integrityscanner.ih"

                // split the first word from the trailing word(s)
Pattern IntegrityScanner::s_firstWord("(\\S+)(\\s+(.*))?");

                // pick up the exit value in testExitValue()
Pattern IntegrityScanner::s_exitValue("(\\d+)\\s*$");
