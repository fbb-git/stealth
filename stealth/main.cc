/*
                              stealth.cc
*/

#include "main.ih"

namespace{

ArgConfig::LongOption longOption[] =
{
//    {"echo-commands", 'e'},   // cancelled, 

    {"max-size", Arg::Required},         // 10m by default

//    {"no-child-processes", 'n'},      // cancelled: use --no-daemon

//    {"only-stdout", 'o'},             // cancelled: use --stdout
    {"config", 'c'},            // : new

    {"log",  'l'},              // : new

    {"mail", 'm'},              // : new

    {"parse-policy-file", 'p'}, // was: 'c'

//    {"quiet", 'q'},           // cancelled: use --verbosity 0

    {"random-interval", 'i'},   // :
    {"run-command", 'r'},       // :

    {"skip-files", 's'},        // :
    {"stdout", 'S'},            // new

    {"syslog", Arg::None},              // new (block)
    {"syslog-facility", Arg::Required},
    {"syslog-priority", Arg::Required},
    {"syslog-tag", Arg::Required},

    {"verbosity", 'V'},         // : new

    {"version", 'v'},
    {"help", 'h'},

    {"repeat", Arg::Required},
    {"keep-alive", Arg::Required},

    {"rerun", Arg::None},               // arg[0] is the runfilename
    {"resume", Arg::None},              // also for this and the next options
    {"suppress", Arg::None},
    {"reload", Arg::None},
    {"terminate", Arg::None},
};

auto endLongOption = longOption + sizeof(longOption) / sizeof(longOption[0]);

}   // anonymous namespace ends
    
int main(int argc, char **argv)
try
{                                       // construct Arg object to process
    ArgConfig &arg = ArgConfig::initialize("c:ehi:l:m:pr:s:SvV:",
                                longOption, endLongOption, 
                                argc, argv); 

    arg.versionHelp(Options::usage, Icmbuild::version, 1);

    Stealth stealth;

    if (not stealth.contactPeer())
        stealth.processPolicy(); // do all policy-file related tasks
}
catch (exception const &err)
{
    if (err.what() != to_string(fmsg.id()))
        cout << err.what() << '\n';
    return 1;
}
catch (int ret)
{
    return ArgConfig::instance().option("hv") ? 0 : ret;
}
catch (...)
{
    cerr << "\n"
            "Stealth terminated with an UNEXPECTED EXCEPTION.\n" <<
            "This should not have happened, please report this error and the "
                                                            "circumstances\n" 
            "causing it to Stealth's author\n";

    return 1;
}
