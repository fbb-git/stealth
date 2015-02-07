#include "options.ih"

Options::Options()
:
    d_arg(ArgConfig::instance()),
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

    setCommandNr();             // sets run-command, (requires foreground).
    setParsePolicy();           // sets the policy file (requires foreground)

    loadPolicy();               // load the policy file and load configuration 
                                // options from the policy file into ArgConfig

    if (d_daemon)
    {
        Util::absPath((*d_policyFile)["BASE"], d_unixDomainSocket);

        if (access(d_unixDomainSocket.c_str(), F_OK) == 0)
            fmsg << "Unix Domain Socket `" << d_unixDomainSocket << 
                    "': already in use, remove it first" << endl;
    }

    setPolicyOptions();
}       



