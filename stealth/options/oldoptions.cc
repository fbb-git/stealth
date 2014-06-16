#include "options.ih"

void Options::oldOptions() const
{
    ostringstream msg;

    int nOld = 0;

    if (d_arg.option('e'))
    {
        ++nOld;
        msg << "    `--echo-commands' was discontinued. "
                                                    "Use --verbosity 2.\n";
    }

    bool usedKeepAlive = d_arg.option(0, "keep-alive");
    if (usedKeepAlive)
    {
        ++nOld;
        msg << "    `--keep-alive' was discontinued. Use --daemon.\n";
    }

    if (d_arg.option('n'))
    {
        ++nOld;
        msg << "    `--no-child-process' was discontinued.\n";
    }

    if (d_arg.option(0, "only-stdout"))
    {
        ++nOld;
        msg << "    `--only-stdout' was discontinued. "
                                            "Consider using --stdout.\n";
    }

    if (d_arg.option('c'))
    {
        ++nOld;
        msg << "    `--parse-config-file' was discontinued. "
                                                "Use --parse-policy-file.\n";
    }

    if (d_arg.option('q'))
    {
        ++nOld;
        msg << "    `--quiet' was discontinued. Use --verbosity 0.\n";
    }

    bool usedSuppress = d_arg.option(0, "suppress");
    if (usedSuppress)
    {
        ++nOld;
        msg << "    `--suppress' was discontinued. Use --suspend.\n";
    }

    if (nOld != 0)
    {
        cerr << "\n" <<
            basename() << " V" << Icmbuild::version << "\n"
            "Obsoleted option(s):\n" <<
            msg.str();

        if (usedKeepAlive or usedSuppress)
        {
            cerr << basename() << " V" << Icmbuild::version << " terminated\n";
            throw 1;
        }
        
        cerr << endl;
    }
}



