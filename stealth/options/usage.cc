#include "options.ih"

void Options::usage(std::string const &progname)
{
    cout <<
        progname << " V" << Icmbuild::version << "\n"
        "SSH-based Trust Enhancement Acquired through a Locally Trusted "
                                                                    "Host\n"
        "Copyright (c) GPL " << Icmbuild::years << "\n"
        "\n"
        "Usage 1 (activation modes):\n"
        "   " << progname << " [options] policy\n"
        "Where:\n"
    "   [options] - optional arguments (short options between parentheses,\n"
    "               option descriptions starting with (C) can only be used\n"
    "               on the command-line and are ignored when specified in "
                                                                    "the\n"
    "               policy file).\n"

    "      --daemon (-d) <path>: (C) run as a background (daemon) process.\n"
    "               <path> is the absolute filename of a pid-file used for\n"
    "               communication with the stealth daemon process\n"

    "      --dry-run: (C) no integrity scans or reloads are performed, but\n"
    "               are assumed OK. Remaining tasks are normally performed\n"

    "      --log (-L) path:   log messages are appended to `path'. If path\n"
    "                   does not exist, it is first created \n"

    "      --logmail: mail is loggeed (requires --log or --syslog)\n"

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
                                                                "actions.\n"
    "                   Specify once to see the numbered commands,\n"
    "                   twice to see the policy file parsing steps as well.\n"
    "                   Results to std output.\n"

    "      --random-interval (-i) value: start integrity scans within\n"
    "                   a random interval of `value' seconds (minutes\n" 
    "                   if an `m' is appended to the specified value).\n"
    "                   Requires --repeat.\n"

    "      --repeat value: start an integrity scan every `value' seconds\n"
    "                   (minutes if an `m' is appended to the specified "
                                                                "value).\n"

    "      --run-command (-r) value: (C) only execute command #`value'\n"

    "      --skip-files (-s) path: skip the integrity checks of the\n"
    "                   files having their absolute path names listed in "
                                                                "`path'\n"

    "      --stdout (-o): messages are (also) written to stdout "
                                                        "(incompatible\n"
    "                   with the --daemon option)\n"

    "      --syslog: write syslog messages\n"

    "      --syslog-facility fac:  syslog facility to use. By default "
                                                    "DAEMON\n"

    "      --syslog-priority pri:  syslog priority to use. By default "
                                                    "NOTICE\n"

    "      --syslog-tag tag: identifier prefixed to syslog messages. By\n"
    "                   default `" << s_defaultSyslogIdent << "')\n"

    "      --time-stamp <type>: the time-stamps to use. By default UTC.\n"
    "                   (does not apply to syslog-timestamps)\n"

    "      --verbosity (-V) value: determines the amount of logged "
                                                            "information.\n"
    "                   Requires --log or --syslog:\n"
    "                       0: nothing is logged\n"
    "                       1: mode reports and policy commands\n"
    "                       2: also: ipc commands and actions\n"
    "                       3: also: integrity scan informative messages\n"

    "   policy: path to the policy file\n"
    "\n"

    "Usage 2 (IPC modes, all options are command-line only):\n"
    "   " << progname << 
            " {--reload,--rerun,--resume,--suspend,--terminate} pid-file\n"
    "Where:\n"
    "      --reload: reload a " << progname << " process's policy and "
                                                            "skip-files\n"
    "                   files\n"
    "      --rerun: start an integrity scan\n"
    "      --resume: resume " << progname << " after --suspend\n"
    "      --suspend: suspend " << progname << "'s activities\n"
    "                   to continue: --resume; to end: --terminate\n"
    "      --terminate: terminate the " << progname << " daemon\n"
    "   pidfile: file containing the pid of the stealth daemon process.\n"
    "\n"
    "Usage 3 (support mode, all options are command-line only)\n"
    "   " << progname << " {--help,--version}\n"
    "Where:\n"
    "      --help (-h):    provide this help and terminate\n"
    "      --version (-v): show version information and terminate\n"

    "\n";
}







