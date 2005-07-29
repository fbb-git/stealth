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

    Arg::LongOption("keep-alive", Arg::Required),       // runfilename
    Arg::LongOption("suppress", Arg::Required),         // runfilename
    Arg::LongOption("repeat", Arg::Required),
    Arg::LongOption("rerun", Arg::Required),
    Arg::LongOption("terminate", Arg::Required),        // runfilename
    Arg::LongOption("resume", Arg::Required),           // runfilename
    
    Arg::LongOption("usage"),
    Arg::LongOption("help"),
};

static Arg::LongOption const * const longOpt_end = 
       longOpt_begin + sizeof(longOpt_begin) / sizeof(Arg::LongOption);
    
int main(int argc, char **argv)
try
{
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
        Util::setDebug(arg.option('d'));

                                        // handle process control options
        Util::processControlOptions();  


        ConfigFile configfile(arg[0]);  // ConfigFile object reads
                                        // configuration file 

        if (!configfile)                // No configfile, then show message
            Util::exit(1, "Can't read configuration file `%s'", arg[0]);

                                        // ConfigSorter sorts the 
                                        // configuration file. Separates
                                        // USEs, DEFINEs and commands.
        ConfigSorter sorter(configfile);

        Reporter reporter(sorter["REPORT"]);

        Scanner scanner(sorter, reporter);  // Construct the integrityscanner

#ifdef DEBUG
        dout("SH and SSH childprocesses are now active. Press Enter...");
        string enter;
        if (arg.option('d'))  
            getline(cin, enter);
#endif

        Util::maybeBackground();        // maybe run Stealth in the background

                                            // Contruct the process monitor
        Monitor monitor(sorter, reporter, scanner); 

        monitor.control();              // control the scanning process,
                                        // run all the Scanner's tests
    }
    catch (Errno const &err)
    {
        cerr << err.what() << ": " << err.why() << endl;
        throw Util::ERROR; // return 1;
    }

    Util::unlinkRunfile();
    return 0;
}
catch (Util::Terminate terminate)
{
    if (Util::mainProcess())
        Scanner::killChildren();
        
    return terminate;
}



