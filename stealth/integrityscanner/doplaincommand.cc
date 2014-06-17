#include "integrityscanner.ih"

void IntegrityScanner::doPlainCommand(Process &child)
{
    nextCommand(child, s_firstWord[0]); // start the next command
    waitForSentinel(child);             // read its output
}
