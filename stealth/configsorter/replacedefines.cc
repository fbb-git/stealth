#include "configsorter.h2"

void ConfigSorter::replaceDefines(string &text)
{
    Pattern define("(\\$\\{([a-zA-Z0-9_]+)\\})");   // [0]: all text,
                                                    // [1]: all ${NAME} text
                                                    // [2]: NAME itself

    dout("ConfigSorter::replaceDefines in " << text);

    string out;

    while (define.match(text))                      // Got a ${NAME}
    {
        out += define.before();                     // Get all before ${NAME}

        out +=                                      // Add:
            hasDEFINE(define[2]) ?                  // if NAME is DEFINEd
                getDEFINE(define[2])                // then its definition
            :                                       // otherwise
                define.match();                     // ${NAME} (unmodified)

        dout("    step: " << out);

        text = define.beyond();                     // remove all matched 
    }                                               // text from `text'

    dout("ConfigSorter::replaceDefines -> " << text);

    text = out + text;                              // redefine `text'
}

