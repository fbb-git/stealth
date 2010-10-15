#include "configsorter.ih"

void ConfigSorter::replaceDefines(string &text)
{
//    Pattern define("(\\$\\{([a-zA-Z0-9_]+)\\})");   // [0]: all text,
//                                                    // [1]: all ${NAME} text
//                                                    // [2]: NAME itself

    Util::debug() << "ConfigSorter::replaceDefines in " << text << "\n";

    string out;

    while (s_define << text)                        // Got a ${NAME}
    {
        out += s_define.before();                   // Get all before ${NAME}

        out +=                                      // Add:
            hasDEFINE(s_define[2]) ?                // if NAME is DEFINEd
                getDEFINE(s_define[2])              // then its definition
            :                                       // otherwise
                s_define.matched();                 // ${NAME} (unmodified)

        Util::debug() << "    step: " << out << "\n";

        text = s_define.beyond();                   // remove all matched 
    }                                               // text from `text'

    Util::debug() << "ConfigSorter::replaceDefines -> " << text << "\n";

    text = out + text;                              // redefine `text'
}

