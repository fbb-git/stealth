/*
                              stealth.cc

*/

#include "stealth.h"

static Arg::LongOption longOpt_begin[] =
{
    Arg::LongOption("debug", 'd'),
    Arg::LongOption("no-child-processes", 'n'),
    Arg::LongOption("only-stdout", 'o'),
    Arg::LongOption("parse-config-file", 'c'),
    Arg::LongOption("quiet", 'q'),
    Arg::LongOption("random-interval", 'i'),
    Arg::LongOption("run-command", 'r'),
    Arg::LongOption("version", 'v'),

    Arg::LongOption("keep-alive", Arg::None),      
    Arg::LongOption("repeat", Arg::Required),
    Arg::LongOption("rerun", Arg::Required),
    Arg::LongOption("terminate", Arg::Required),
    
    Arg::LongOption("usage"),
    Arg::LongOption("help"),
};

static Arg::LongOption const * const longOpt_end = 
       longOpt_begin + sizeof(longOpt_begin) / sizeof(Arg::LongOption);
    
int main(int argc, char **argv)
{
    signal(SIGCHLD, IOFork::handleTerminatedChild);

    try
    {
                                        // construct Arg object to process
        Arg::initialize("cdi:noqr:v", 
                longOpt_begin, longOpt_end, 
                argc, argv); 
                                        // command-line arguments. 
                                        // Arg is singleton: obtain it
                                        // everwhere using Arg()
        Arg &arg = Arg::getInstance();

        if (arg.option('v'))
            Util::showVersion();                

        Util::processControlOptions();  // handle process control options

        if
        (
            !arg.nArgs()                // provide usage if no arguments
            ||
            arg.option(0, "usage") || arg.option(0, "help")
        )
            Util::usage();              // were received

        ConfigFile configfile(arg[0]);  // ConfigFile object reads
                                        // configuration file 

        if (!configfile)                // No configfile, then show message
            Util::exit(1, "Can't read `%s'", arg[0]);

                                        // ConfigSorter sorts the 
                                        // configuration file. Separates
                                        // USEs, DEFINEs and commands.
        ConfigSorter sorter(configfile);

        if (arg.option('i'))            // do random delay if -i found
            Util::randomDelay();

                                        // Construct the integrityscanner
        Scanner scanner(sorter);

#ifdef DEBUG
        dout("SH and SSH childprocesses are now active. Press Enter...");
        string enter;
        if (arg.option('d'))  getline(cin, enter);
#endif

        if (Util::keepAlive())
        {
            int pid = fork();
            if (pid < 0)
                Util::exit(1, "--keepalive / --rerun failed due to failing "
                                "fork() system call.");

            if (pid > 0)        // parent process gets child pid
                Util::exit(0, "Stealth: pid = %u", pid);

            signal(SIGHUP, Util::handleRerun);
            signal(SIGTERM, Util::handleTerminate);

        }

        scanner.preamble();             // make a test-connection to
                                        // the remote computer
        do
        {
            Util::setAlarm();

            scanner.run();              // run all tests
            scanner.mailReport();       // mail the report

            Util::wait();
        }
        while (Util::keepAlive());

    }
    catch (Errno const &err)
    {
        cerr << err.what() << ": " << err.why() << endl;
        return 1;
    }
    
    Scanner::killChildren();

    return 0;
}

