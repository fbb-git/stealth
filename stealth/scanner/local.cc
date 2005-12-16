#include "scanner.ih"

/*
    At this point: LOCAL was seen. Beyond that, we must see:

    NOTEST  CHECK ...
            CHECK ...
    NOTEST  ...
            ...

    NOTEST  means the return value of the command is not tested
    CHECK   means that the output is compared with a former log
*/

void Scanner::local(string const &d_firstWord2)
{
    Util::debug() << "Command Run At The Controller\n";

    d_firstWord.match(d_firstWord2);                // what's beyond `LOCAL' ?

                                                    // set d_testExitValue
    d_testExitValue = !removeFirstWord("NOTEST");   // according to !NOTEST

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
    {
        if (!doCHECKcommand(d_shFork))              // so, do the command
            d_reporter  << endl                     // and check the result
            << "*** BE CAREFUL *** REMAINING RESULTS MAY BE FORGED" << endl
            << endl;
    }
    else
        doPlainCommand(d_shFork);                   // do unchecked command
}


