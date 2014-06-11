/*
                              stealth.cc
*/

#include "main.ih"

namespace{

Arg::LongOption longOption[] =
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
    Arg &arg = Arg::initialize("cdehi:noqr:s:v", longOption, endLongOption, 
                                argc, argv); 

    arg.versionHelp(Options::usage, Icmbuild::version, 1);

    Stealth stealth;

    if (not stealth.contactPeer())
        stealth.run();                  // run all the Scanner's tests
}
catch (exception const &err)
{
    if (err.what() != to_string(fmsg.id()))
        cerr << err.what() << '\n';
    return 1;
}
catch (int ret)
{
    return Arg::instance().option("hv") ? 0 : ret;
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
