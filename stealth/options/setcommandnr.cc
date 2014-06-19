#include "options.ih"

void Options::setCommandNr()
{
    string value;
    if (not d_arg.option(&value, 'r'))
        return;

    foregroundOnly("run-command");

    try
    {
        d_commandNr = stoul(value);
        if (d_commandNr == 0)
            fmsg << "--run-command 0: not a valid (natural) command number" << 
                                                                        endl;
        if (not d_stdout)
        {
            d_stdout = true;
            d_multiStreambuf.insert(cout);
        }
    }
    catch (...)
    {
        d_commandNr = 0;
        fmsg << "--run-command " << value << ": invalid command number" <<
                                                                        endl;
    }
}

