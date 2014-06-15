#include "integrityscanner.ih"

void IntegrityScanner::doPlainCommand(Process &child)
{
    m1 << "unchecked command: `" << s_firstWord[0] << '\'' << endl;
    if (!d_arg.option('n'))                 // unless -n (no execute commands)
    {
        nextCommand(child, s_firstWord[0]); // start the next command
        waitForSentinel(child);             // read its output
    }
}
