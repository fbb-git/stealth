#include "configsorter.h2"

pair<string, string> const
    ConfigSorter::s_defaultKeyword[] =
    {
        pair<string,string>("BASE",     "."),
        pair<string,string>("DIFF",     "/usr/bin/diff"),
        pair<string,string>("EMAIL",    "root"),
        pair<string,string>("MAILER",   "/usr/bin/mail"),
        pair<string,string>("REPORT",   "report"),
        pair<string,string>("SH",       "/bin/sh"),
        pair<string,string>("MAILARGS", "-s \"STEALTH scan report\""),
    };

unsigned ConfigSorter::s_nDefaultKeywords =
                sizeof(s_defaultKeyword) / sizeof(pair<string, string>);
