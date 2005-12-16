#include "configsorter.ih"

void ConfigSorter::replaceDefines(string &text)
{
    Pattern define("(\\$\\{([a-zA-Z0-9_]+)\\})");   // [0]: all text,
                                                    // [1]: all ${NAME} text
                                                    // [2]: NAME itself

    Util::debug() << "ConfigSorter::replaceDefines in " << text << endl;

    string out;

    while (define << text)                          // Got a ${NAME}
    {
        out += define.before();                     // Get all before ${NAME}

        out +=                                      // Add:
            hasDEFINE(define[2]) ?                  // if NAME is DEFINEd
                getDEFINE(define[2])                // then its definition
            :                                       // otherwise
                define.matched();                   // ${NAME} (unmodified)

        Util::debug() << "    step: " << out << endl;

        text = define.beyond();                     // remove all matched 
    }                                               // text from `text'

    Util::debug() << "ConfigSorter::replaceDefines -> " << text << endl;

    text = out + text;                              // redefine `text'
}

