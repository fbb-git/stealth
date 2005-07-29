#include "scanner.h2"

void Scanner::doPlainCommand(IOFork &child)
{
    if (Util::debug())
        cerr << "running unchecked command: `" << d_firstWord[0] << "'\n";

    if (!Arg::getInstance().option('n'))    // unless -n (no execute commands)
    {
        nextCommand(child.out(),            // start the next command
                        d_firstWord[0]);    

        waitForSentinel(child.in());        // read its output
    }
}
