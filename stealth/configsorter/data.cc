#include "configsorter.ih"

pair<string, string> const
    ConfigSorter::s_defaultKeyword[] =
    {
        pair<string,string>("BASE",         "."),
        pair<string,string>("DD",           "/bin/dd"),
        pair<string,string>("DIFF",         "/usr/bin/diff"),
        pair<string,string>("DIFFPREFIX",   "2"),
        pair<string,string>("EMAIL",        "root"),
        pair<string,string>("MAILER",       "/usr/bin/mail"),
        pair<string,string>("REPORT",       "report"),
        pair<string,string>("SH",           "/bin/sh"),
        pair<string,string>("MAILARGS",     "-s \"STEALTH scan report\""),
    };

size_t ConfigSorter::s_nDefaultKeywords =
                sizeof(s_defaultKeyword) / sizeof(pair<string, string>);

Pattern ConfigSorter::s_firstWord("^\\s*([-_[:alnum:]]+)\\s+(.*)");
Pattern ConfigSorter::s_comment("^\\s*[#]?");
Pattern ConfigSorter::s_define("(\\$\\{([-_[:alnum:]]+)\\})");   
                                                    // [0]: all text,
                                                    // [1]: all ${NAME} text
                                                    // [2]: NAME itself

