#include "scanner.ih"

void Scanner::doPlainCommand(Process &child)
{
    msg() << "running unchecked command: `" << s_firstWord[0] << '\'' << info;
    if (!Arg::instance().option('n'))    // unless -n (no execute commands)
    {
        nextCommand(child, s_firstWord[0]); // start the next command
        waitForSentinel(child);             // read its output
    }
}
