#include "policyfile.ih"

pair<string, string> const
    PolicyFile::s_defaultKeyword[] =
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

size_t PolicyFile::s_nDefaultKeywords =
                sizeof(s_defaultKeyword) / sizeof(pair<string, string>);

Pattern PolicyFile::s_firstWord("^\\s*([-_[:alnum:]]+)\\s+(.*)");
Pattern PolicyFile::s_comment("^\\s*[#]?");
Pattern PolicyFile::s_define("(\\$\\{([-_[:alnum:]]+)\\})");   
                                                    // [0]: all text,
                                                    // [1]: all ${NAME} text
                                                    // [2]: NAME itself

