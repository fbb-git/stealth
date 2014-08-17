#include "options.ih"

void Options::usage(std::string const &progname)
{
    cout <<
        progname << " by " << Icmbuild::author << "\n"
        "\n" <<
        progname << " V" << Icmbuild::version << "\n"
        "SSH-based Trust Enhancement Acquired through a Locally Trusted "
                                                                    "Host\n"
        "Copyright (c) GPL " << Icmbuild::years << "\n"
        "\n"
        "Usage 1:\n"
        "   " << progname << " [options] policy\n"
        "Where:\n"
    "   [options] - optional arguments (short options between parentheses,\n"
    "               option descriptions starting with (C) can only be used\n"
    "               on the command-line and are ignored when specified in "
                                                                    "the\n"
    "               policy file.n"

    "      --daemon (-d) pidfile: (C) run as a background (daemon) process\n"

    "      --dry-run: (C) no integrity scans or reloads are performed, but\n"
    "               are assumed OK. Remaining tasks are normally performed\n"

    "      --help (-h):       (C) provide this help\n"

    "      --log (-L) path:   log messages are appended to `path'. If path\n"
    "                   does not exist, it is first created \n"

    "      --logmail: mail is loggeed (requires --log or --syslog\n"

    "      --max-size value[BKMG]: files retrieved by GET may at most\n"
    "                   have `value' bytes (B), Kbytes (K), Mbytes (M), "
                                                            "Gbytes (G).\n"
    "                   By default: 10M; The default unit is `B'\n"

    "      --no-mail: mail is not sent. By default mail is sent as "
                                                                "configured\n"
    "                   in the policy-file (--logmail can be specified "
                                                             "independently\n"
    "                   from --no-mail)\n"

    "      --parse-policy-file (-p): (C) parse the policy file, no further "
                                                                "action.\n"
    "                   Specify once to see the numbered commands, twice to\n"
    "                   add the policy file parsing steps.\n"
    "                   Results to std output.\n"

    "      --random-interval (-i) value: start integrity scans within\n"
    "                   a random interval of `value' seconds ("
                                                                "minutes\n" 
    "                   if an `m' is appended) after the --repeat "
                                                                "interval.\n"
    "                   Requires --repeat and --daemon.\n"

    "      --repeat value: start an integrity scan every `value' seconds\n"
    "                   Requires --daemon.\n"

    "      --run-command (-r) value: (C) only execute command #`value'\n"

    "      --skip-files (-s) file: skip the integrity checks of the\n"
    "                   files having their absolute path names listed in "
                                                                "`file'\n"

    "      --stdout (-o): messages are (also) written to stdout (not "
                                                                "available\n"
    "                   for --daemon)\n"

    "      --syslog: write syslog messages\n"

    "      --syslog-facility fac:  syslog facility to use. By default:\n" <<
    "                   " << s_defaultSyslogFacility << "')\n"

    "      --syslog-priority pri:  syslog priority to use. By default:\n" <<
    "                   " << s_defaultSyslogPriority << "')\n"

    "      --syslog-tag tag: identifier prefixed to syslog messages. By\n"
    "                   default `" << s_defaultSyslogIdent << "')\n"

    "      --verbosity value: determines the amount of logged information.\n"
    "                   Requires --log or --syslog:\n"
    "                       0: nothing is logged\n"
    "                       1: mode reports and policy commands\n"
    "                       2: ipc commands and actions\n"
    "                       3: integrity scan informative messages\n"

    "      --version (-v): (C) show version information and terminate\n"

    "   policy: path to the policy file\n"
    "\n"

    "Usage 2:\n"
    "   " << progname << 
            " {--reload,--rerun,--resume,--suspend,--terminate} pidfile\n"
    "Where:\n"
    "      --reload: reload a " << progname << " process's configuration "
                                                                "files\n"
    "      --rerun: start an integrity scan\n"
    "      --resume: resume " << progname << " after --suspend\n"
    "      --suspend: suspend " << progname << "'s activities\n"
    "                  to continue: --resume; to end: --terminate\n"
    "      --terminate: terminate the " << progname << " daemon\n"
    "   pidfile: file containing the pid of the stealth daemon process.\n"
    "\n";
}







