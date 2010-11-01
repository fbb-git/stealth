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

void Scanner::local(string const &s_firstWord2)
{
    imsg << "Command Run At The Controller" << endl;

    s_firstWord.match(s_firstWord2);                // what's beyond `LOCAL' ?

                                                    // set d_testExitValue
    d_testExitValue = !removeFirstWord("NOTEST");   // according to !NOTEST

    if  (removeFirstWord("CHECK"))                  // ...      CHECK ...
    {
        if (!doCHECKcommand(d_shFork))              // so, do the command
            d_reporter  << "\n"                     // and check the result
               "*** BE CAREFUL *** REMAINING RESULTS MAY BE FORGED\n" <<
               endl;
    }
    else
        doPlainCommand(d_shFork);                   // do unchecked command
}


