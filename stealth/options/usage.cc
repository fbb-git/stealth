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
    "               configuration file (see also option --config)\n"

    "      --config (-C) path: (C) config file containing long option "
                                                            "specifications\n"
    "                         (default `$HOME/" <<
                                    s_defaultConfigFile << ")`\n"

    "      --help (-h):       (C) provide this help\n"

    "      --daemon (-d) pidfile: (C) keep running as a daemon, wake up at\n"
    "                         interrupts.\n"

    "      --log (-L) path:   log messages are appended to `path'. If "
                                                                    "path\n"
    "                         does not exist, it is created first\n"

    "      --mail (-m) action - specify 'action' to determine mail "
                                                            "handling:\n"
    "                         off: mail is not sent, log: mail is logged,\n"
    "                         by default the policy-file configuration is "
                                                            "used\n"
    "      --max-size value[BKMG]: files retrieved by GET may at most\n"
    "           have `value' bytes (B), Kbytes (K), Mbytes (M), "
                                                            "Gbytes (G)\n"
    "           default: 10M; default unit: B\n"

    "      --parse-policy-file (-p): (C) parse the policy file, no further "
                                                                "action.\n"
    "                         Results to std output.\n"

    "      --random-interval (-i) value: start integrity scans within\n"
    "                         a random interval of `value' seconds ("
                                                                "minutes\n" 
    "                         if an `m' is appended) after the --repeat "
                                                                "interval.\n"
    "                         Requires --repeat and --daemon.\n"

    "      --repeat value: start an integrity scan every `value' seconds\n"
    "                         Requires --daemon.\n"

    "      --run-command (-r) value: (C) only execute command #`value'\n"

    "      --skip-files (-s) file: skip the integrity checks of the\n"
    "            files having their absolute path names listed in `file'\n"

    "      --stdout (-o)    - messages are (also) written to stdout\n"
    "                         (not available for --daemon)\n"

    "      --syslog         - write syslog messages\n"
    "      --syslog-facility fac  - fac: syslog facility to use\n"
    "                         (default `" << s_defaultSyslogFacility << "')\n"
    "      --syslog-priority pri  - pri: syslog priority to use\n"
    "                         (default `" << s_defaultSyslogPriority << "')\n"
    "      --syslog-tag id  - id: identifier prefixed to syslog "
                                                                "messages\n"
    "                         (default `" << s_defaultSyslogIdent << "')\n"

    "      --verbosity value - determines the amount of logged "
                                                            "information.\n"
    "                         Requires --log, --stdout, or --syslog:\n"
    "                           0: nothing is logged\n"
    "                           1: active modes are logged\n"
    "                           2: policy-commands are logged\n"
    "                           3: \n"

    "      --version (-v)   - (C) show version information and terminate\n"

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
    "   pidfile: file containing the pid of the stealth daemon process to "
                                                            "signal.\n"
    "\n";
}
