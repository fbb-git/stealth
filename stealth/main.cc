/*
                              stealth.cc
*/

#include "main.ih"

namespace{

ArgConfig::LongOption longOption[] =
{
    // Kept for backward compatibility, but a warning is genereated when
    // used
    {"echo-commands", 'e'},             // discont., use --log
    {"keep-alive", Arg::None},          // discont.: use --daemon
    {"only-stdout", Arg::None},         // discont.: use --stdout
    {"parse-config-file", 'c'},         // discont.: use --parse-policy-file
    {"quiet", 'q'},                     // discont.: use --verbosity 0
    {"suppress", Arg::None},            // discont.: use --suspend


    {"max-size", Arg::Required},         // 10m by default


    {"config", 'C'},            // : new

    {"log",  'l'},              // : new

    {"log-mail", Arg::None},    // new
    {"no-mail", Arg::None},     // new

    {"parse-policy-file", 'p'}, // was: 'c'

    {"random-interval", 'i'},   // :
    {"run-command", 'r'},       // :

    {"skip-files", 's'},        // :
    {"stdout", 'o'},            // new

    {"syslog", Arg::None},              // new (block)
    {"syslog-facility", Arg::Required},
    {"syslog-priority", Arg::Required},
    {"syslog-tag", Arg::Required},

    {"verbosity", 'V'},         // : new

    {"version", 'v'},
    {"help", 'h'},

    {"repeat", Arg::Required},

    {"daemon", 'd'},

    {"rerun", Arg::None},               // arg[0] is the runfilename
    {"resume", Arg::None},              // also for this and the next options
    {"suspend", Arg::None},
    {"reload", Arg::None},
    {"terminate", Arg::None},
};

auto endLongOption = longOption + sizeof(longOption) / sizeof(longOption[0]);

}   // anonymous namespace ends
    
int main(int argc, char **argv)
try
{                                       // construct Arg object to process
    ArgConfig &arg = ArgConfig::initialize("cC:d:ehi:l:nopqr:s:vV:",
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
