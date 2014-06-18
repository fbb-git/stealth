#include "options.ih"

void Options::checkAction() const
{
            // only one of these options may be specified

    if (d_daemon + d_reload + d_rerun + d_resume + d_suspend + d_terminate > 1)
    {
        fmsg << "incompatible options:";

        if (d_daemon)
            fmsg << " --daemon";

        if (d_reload)
            fmsg << " --reload";

        if (d_rerun)
            fmsg << " --rerun";

        if (d_resume)
            fmsg << " --resume";

        if (d_suspend)
            fmsg << " --suspend";

        if (d_terminate)
            fmsg << " --terminate";
        
        fmsg << endl;
    }
}








