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

    Arg::LongOption("keep-alive", Arg::Required),      
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

        ConfigFile configfile(arg[0]);  // ConfigFile object reads
                                        // configuration file 

        if (!configfile)                // No configfile, then show message
            Util::exit(1, "Can't read configuration file `%s'", arg[0]);

                                        // ConfigSorter sorts the 
                                        // configuration file. Separates
                                        // USEs, DEFINEs and commands.
        ConfigSorter sorter(configfile);

                                        // handle process control options
        Util::processControlOptions(sorter["RUNBASE"]);  

        Scanner scanner(sorter);        // Construct the integrityscanner

#ifdef DEBUG
        dout("SH and SSH childprocesses are now active. Press Enter...");
        string enter;
        if (arg.option('d'))  getline(cin, enter);
#endif

        Util::maybeBackground();        // maybe run Stealth in the background

        scanner.preamble();             // make a test-connection to
                                        // the remote computer

        scanner.scanLoop();             // run all tests in a loop
    }
    catch (Errno const &err)
    {
        cerr << err.what() << ": " << err.why() << endl;
        return 1;
    }
    
    Scanner::killChildren();
    Util::unlinkRunfile();

    return 0;
}

