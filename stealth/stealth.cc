/*
                              stealth.cc

*/

#include "stealth.ih"

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
    {"help", 'h'},

    {"repeat", Arg::Required},
    {"keep-alive", Arg::Required},

    {"rerun", Arg::None},               // arg[0] is the runfilename
    {"resume", Arg::None},              // also for this and the next options
    {"suppress", Arg::None},
    {"terminate", Arg::None},
};

Arg::LongOption const * const longOpt_end = 
       longOpt_begin + sizeof(longOpt_begin) / sizeof(Arg::LongOption);

}   // anonymous namespace ends
    
int main(int argc, char **argv)
try
{
                                        // construct Arg object to process
    Arg &arg = Arg::initialize("cdehi:noqr:s:v", longOpt_begin, longOpt_end, 
                                argc, argv); 

    arg.versionHelp(usage, version, 1);

    Msg::setDisplay(cerr);
    if (!arg.option('d'))
        Msg::setDisplay(Msg::INFO, false);

    Monitor monitor;
    monitor.control();              // control the scanning process,
                                    // run all the Scanner's tests
}
catch (Errno const &err)
{
    if (err.which())
        cerr << err.why() << '\n';
    return err.which();
}
catch (int ret)
{
    return ret;
}
catch (...)
{
    cerr << "\n"
            "Program ended due to an UNEXPECTED EXCEPTION.\n"
            "This should not happen, please report this error and the "
                                                            "circumstances\n" 
            "causing it to Stealth's author\n";

    return 1;
}






