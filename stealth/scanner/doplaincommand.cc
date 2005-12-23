#include "scanner.ih"

void Scanner::doPlainCommand(Process &child)
{
    Util::debug() << "running unchecked command: `" << s_firstWord[0] << "'"
                                                                    << endl;

    if (!Arg::instance().option('n'))    // unless -n (no execute commands)
    {
        nextCommand(child,                  // start the next command
                        s_firstWord[0]);    

        waitForSentinel(child);             // read its output
    }
}
