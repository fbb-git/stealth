#include "configsorter.ih"

void ConfigSorter::replaceDefines(string &text)
{
//    Pattern define("(\\$\\{([a-zA-Z0-9_]+)\\})");   // [0]: all text,
//                                                    // [1]: all ${NAME} text
//                                                    // [2]: NAME itself

    msg() << "ConfigSorter::replaceDefines in " << text << info;

    string out;

    while (s_define << text)                        // Got a ${NAME}
    {
        out += s_define.before();                   // Get all before ${NAME}

        out +=                                      // Add:
            hasDEFINE(s_define[2]) ?                // if NAME is DEFINEd
                getDEFINE(s_define[2])              // then its definition
            :                                       // otherwise
                s_define.matched();                 // ${NAME} (unmodified)

        msg() << "    step: " << out << info;

        text = s_define.beyond();                   // remove all matched 
    }                                               // text from `text'

    msg() << "ConfigSorter::replaceDefines -> " << text << info;

    text = out + text;                              // redefine `text'
}

