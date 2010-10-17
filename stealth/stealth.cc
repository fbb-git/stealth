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

    {"keep-alive", Arg::Required},       // runfilename
    {"suppress", Arg::Required},         // runfilename
    {"repeat", Arg::Required},
    {"rerun", Arg::Required},
    {"terminate", Arg::Required},        // runfilename
    {"resume", Arg::Required},           // runfilename
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

    Monitor monitor(arg[0]);
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






