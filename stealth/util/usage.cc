#include "util.h2"

void Util::usage()
{
    string stealth = Arg::getInstance().basename();

    cerr <<
        stealth << " by Frank B. Brokken (f.b.brokken@rc.rug.nl)\n"     <<
        "\n"                                                            <<
        stealth << " V" << version << "\n"                              <<
        "SSH-based Trust Enhancement Acquired through a Locally "       <<
                                                    "Trusted Host\n"    <<
        "Copyright (c) GPL " << year << "\n"                            <<
        "\n"                                                            <<
        "Usage 1:\n"                                                    <<
        "   " << stealth << " options policy\n"                         <<
        "Where:\n"                                                      <<
        "   options: (long options between parentheses) select from:\n" <<
        "       -d: (--debug) write debug messages to std error\n"      <<
        "       -c: (--parse-config-file) process the config file,\n"   <<
        "           no further action, report the results to std "      <<
                                                           "output.\n"  <<
        "       -i <interval>[m]: (--random-interval) start the "       <<
                                            "scan between now and \n"   <<
        "           a random interval of interval seconds, or "         <<
                                                            "minutes\n" <<
        "           if an `m' is appended immediately after"            <<
                                        " the specified interval.\n"    <<
        "       -n: (--no-child-processes) no child processes are\n"    <<
        "            executed: child actions are faked to be OK.\n"     <<
        "       -o: (--only-stdout) scan report is written to "         <<
                                    "stdout. No mail is sent.\n"        <<
        "       -q: (--quiet) suppress progress messages to stderr.\n"  <<
        "       -r <nr>: (--run-command) only run command <nr> "        <<
                                                "(natural  number).\n"  <<
        "       -v: (--version): display version information (and "     <<
                                                            "exit).\n"  <<
        "   --keep-alive <suffix>: keep running as a daemon, wake up"   <<
                                                   " at interrupts.\n"  <<
        "   --repeat <seconds>: keep running as a daemon, wake up at\n" <<
        "           interrupts. or after <seconds> seconds.\n"          <<
        "           Requires --keep-alive.\n"                           <<
        "   --usage: provide this help (and exit)\n"                    <<
        "   --help: provide this help (and exit)\n"                     <<
        "   policy: path to the policyfile\n"                           <<
        "\n"                                                            <<
        "Usage 2:\n"                                                    <<
        "   " << stealth << " [--rerun|--terminate] <suffix> policy\n"  <<
        "Where:\n"                                                      <<
        "   --rerun: restart the scan of " << stealth << "\n"           << 
        "   --terminate: terminate << stealth << "\n"                   <<
        "   <suffix>: suffix to use with a PIDFILE.\n"                  <<
        "   policy: path to the policyfile\n"                           <<
        endl;

    ::exit(1);
}
