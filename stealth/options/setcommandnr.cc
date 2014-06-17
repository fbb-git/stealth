#include "options.ih"

void Options::setCommandNr()
{
    string value;
    if (not d_arg.option(&value, 'r'))
        return;

    if (d_daemon || ipc())
    {
        wmsg << "--run-command cannot be performed by a " << basename() <<
                                                    " daemon process" << endl;
        d_commandNr = 0;
        return;
    }

    try
    {
        d_commandNr = stoul(value);
        if (d_commandNr == 0)
            wmsg << "--run-command 0: not a valid (natural) command number" << 
                                                                        endl;
    }
    catch (...)
    {
        d_commandNr = 0;
        wmsg << "--run-command " << value << ": invalid command number" <<
                                                                        endl;
    }
}
