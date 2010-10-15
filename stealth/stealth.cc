/*
                              stealth.cc

*/

#include "stealth.h"

namespace{

Arg::LongOption longOpt_begin[] =
{
    {"debug", 'd'},
    {"echo-commands", 'e'},
    {"max-size", Arg::Required},         // 10m by default
    {"no-child-processes", 'n'},
    {"only-stdout", 'o'},
    {"parse-config-file", 'c'},
    {"quiet", 'q'},
    {"random-interval", 'i'},
    {"run-command", 'r'},
    {"skip-files", 's'},
    {"version", 'v'},

    {"keep-alive", Arg::Required},       // runfilename
    {"suppress", Arg::Required},         // runfilename
    {"repeat", Arg::Required},
    {"rerun", Arg::Required},
    {"terminate", Arg::Required},        // runfilename
    {"resume", Arg::Required},           // runfilename

    Arg::LongOption("usage"),
    Arg::LongOption("help"),
};

Arg::LongOption const * const longOpt_end = 
       longOpt_begin + sizeof(longOpt_begin) / sizeof(Arg::LongOption);

}   // anonymous namespace ends
    
int main(int argc, char **argv)
try
{
    try
    {
                                        // construct Arg object to process
        Arg &arg = Arg::initialize("cdei:noqr:s:v", 
                longOpt_begin, longOpt_end, 
                argc, argv); 

        bool debug = arg.option('d');
        Util::setDebug(debug);

                                        // handle process control options
        Util::processControlOptions();  

        Util::maybeBackground();        // maybe run Stealth in the background


        ConfigFile configfile;          // ConfigFile object reads
                                        // configuration file 
        try
        {
            configfile.open(arg[0]);
        }
        catch (...)                     // No configfile, then show message
        {
            Util::exit("Can't read configuration file `%s'", arg[0]);
        }
                                        // ConfigSorter sorts the 
                                        // configuration file. Separates
                                        // USEs, DEFINEs and commands.
        ConfigSorter sorter(configfile);

        Reporter reporter(sorter["REPORT"]);

        Scanner scanner(sorter, reporter);  // Construct the integrityscanner

                                            // Contruct the process monitor
        Monitor monitor(sorter, reporter, scanner); 

        monitor.control();              // control the scanning process,
                                        // run all the Scanner's tests
    }
    catch (Errno const &err)
    {
        cerr << err.why() << ": " << err.which() << '\n';
        throw Util::ERROR;              // return 1;
    }

    Util::unlinkRunfile();
}
catch (Util::Terminate terminate)   // may also be OK
{
    Util::mainProcess();
    return terminate;
}

