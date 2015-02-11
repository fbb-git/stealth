#include "options.ih"

// No log-files are available yet. But since Options is constructed while
// stealth runs in the foreground, error messages can be sent to cerr.

Options::Options()
:
    d_arg(ArgConfig::instance()),
    d_base(getCwd()),
    d_maxSizeStr("10M"),
    d_repeatInterval(numeric_limits<int>::max())
{
    
    requireSomeArgument();      // no args/options, then usage and ends.

    oldOptions();               // ends if --keep-alive or --suppress was 
                                // specified

    setMode();                  // sets d_mode and all bool mode indicators
    checkMode();                // ends if multiple/incompatible modes were
                                // set

    d_dryrun = d_arg.option(0, "dry-run");

                                // preset file name options when defined as
                                // command-line options, using base = cwd
    d_cmdLineOption = setLog() | setSkipFile();

    setCommandNr();             // sets run-command, (requires foreground).
    setParsePolicy();           // sets the policy file (requires foreground)

    setPolicyPath();

//  loadPolicy();               // load the policy file and load configuration 
//                              // options from the policy file into ArgConfig

    if (d_daemon)
    {
        Util::absPath(d_base, d_unixDomainSocket);

        if (access(d_unixDomainSocket.c_str(), F_OK) == 0)
            fmsg << "Unix Domain Socket `" << d_unixDomainSocket << 
                    "': already in use, remove it first" << endl;
    }

    setConfigOptions();

    if 
    (
        not d_skipFile.empty()
        and 
        access(d_skipFile.c_str(), R_OK) != 0
    )
        fmsg << "Can't read skip-file `" << d_skipFile << '\'' << endl;


}       



