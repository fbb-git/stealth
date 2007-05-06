#include <string>
#include <iostream>

using namespace std;

void usage(string const &stealth, string const &version, string const &year)
{
    cout <<
        stealth << " by Frank B. Brokken (f.b.brokken@rug.nl)\n"
        "\n" <<
        stealth << " V" << version << "\n"
        "SSH-based Trust Enhancement Acquired through a Locally "
                                                    "Trusted Host\n"
        "Copyright (c) GPL " << year << "\n"
        "\n"
        "Usage 1:\n"
        "   " << stealth << " options policy\n"
        "Where:\n"
        "   options: (long options between parentheses) select from:\n"
        "       -c: (--parse-config-file) process the config file,\n"
        "           no further action, report the results to std output.\n"
        "       -d: (--debug) write debug messages to std error\n"
        "       -e: (--echo-commands) echo commands to std error when they\n"
        "           are processed (implied by -d)\n"
        "       -i <interval>[m]: (--random-interval) start the "
                                            "scan between now and\n"
        "           a random interval of interval seconds, or minutes\n"
        "           if an `m' is appended to the specified interval.\n"
        "       -n: (--no-child-processes) no child processes are\n"
        "            executed: child actions are faked to be OK.\n"
        "       -o: (--only-stdout) scan report is written to "
                                    "stdout. No mail is sent.\n"
        "       -q: (--quiet) suppress progress messages to stderr.\n"
        "       -r <nr>: (--run-command) only run command <nr> "
                                                "(natural  number).\n"
        "       -v: (--version): display version information (and exit).\n"
        "   --keep-alive pidfile: keep running as a daemon, wake up"
                                                   " at interrupts.\n"
        "   --repeat <seconds>: keep running as a daemon, wake up at\n"
        "           interrupts. or after <seconds> seconds.\n"
        "           Requires --keep-alive.\n"
        "   --usage: provide this help (and exit)\n"
        "   --help: provide this help (and exit)\n"
        "   policy: path to the policyfile\n"
        "\n"
        "Usage 2:\n"
        "   " << stealth << " [--rerun|--resume|--suppress|--terminate] "
                                                                "pidfile\n"
        "Where:\n"
        "   --rerun: restart a " << stealth << " integrity scan\n"
        "   --resume: resume " << stealth << " following --suppress\n"
        "   --suppress: suppress " << stealth << " activities\n"
        "   --terminate: terminate "<< stealth << "\n"
        "   pidfile: file containing the pid of the stealth process to "
                                                                "rerun or\n"
        "            terminate.\n" <<
        endl;
}
